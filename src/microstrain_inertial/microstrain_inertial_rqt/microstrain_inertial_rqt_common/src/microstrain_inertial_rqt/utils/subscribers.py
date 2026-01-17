import math
from nav_msgs.msg import Odometry
from sensor_msgs.msg import Imu, MagneticField, NavSatFix
#from microstrain_inertial_msgs.msg import GNSSAidingStatus, GNSSFixInfo, GNSSDualAntennaStatus, FilterStatus, RTKStatusV1, RTKStatus, FilterAidingMeasurementSummary

from microstrain_inertial_msgs.msg import HumanReadableStatus, MipGnssFixInfo, MipGnssCorrectionsRtkCorrectionsStatus, MipFilterGnssDualAntennaStatus, MipFilterGnssPositionAidingStatus, MipFilterAidingMeasurementSummary

from .constants import _DEFAULT_VAL, _DEFAULT_STR
from .constants import _UNIT_DEGREES, _UNIT_GS, _UNIT_GUASSIAN, _UNIT_METERS, _UNIT_RADIANS, _UNIT_METERS_PER_SEC, _UNIT_RADIANS_PER_SEC
from .constants import _ICON_GREY_UNCHECKED_MEDIUM, _ICON_YELLOW_UNCHECKED_MEDIUM, _ICON_YELLOW_CHECKED_MEDIUM, _ICON_GREEN_UNCHECKED_MEDIUM,_ICON_GREEN_CHECKED_MEDIUM, _ICON_TEAL_UNCHECKED_MEDIUM, _ICON_TEAL_CHECKED_MEDIUM, _ICON_BLUE_UNCHECKED_MEDIUM, _ICON_BLUE_CHECKED_MEDIUM, _ICON_RED_UNCHECKED_MEDIUM, _ICON_RED_CHECKED_MEDIUM
from .common import SubscriberMonitor


class GNSSAidingStatusMonitor(SubscriberMonitor):

  def __init__(self, node, node_name, topic_name):
    super(GNSSAidingStatusMonitor, self).__init__(node, node_name, topic_name, MipFilterGnssPositionAidingStatus)

  @property
  def tight_coupling(self):
    return self._get_val(self._current_message.status.tight_coupling)

  @property
  def differential_corrections(self):
    return self._get_val(self._current_message.status.differential_corrections)

  @property
  def integer_fix(self):
    return self._get_val(self._current_message.status.integer_fix)

  @property
  def position_fix(self):
    return self._get_val(not self._current_message.status.no_fix)
  
  @property
  def tight_coupling_string(self):
    return self._get_small_boolean_icon_string(self.status.tight_coupling)

  @property
  def differential_corrections_string(self):
    return self._get_small_boolean_icon_string(self.status.differential_corrections)

  @property
  def integer_fix_string(self):
    return self._get_small_boolean_icon_string(self.status.integer_fix)

  @property
  def position_fix_string(self):
    return self._get_small_boolean_icon_string(self.position_fix)


class GNSSFixInfoMonitor(SubscriberMonitor):

  def __init__(self, node, node_name, topic_name):
    super(GNSSFixInfoMonitor, self).__init__(node, node_name, topic_name, MipGnssFixInfo)

  @property
  def fix_type(self):
    return self._get_val(self._current_message.fix_type)

  @property
  def num_sv(self):
    return self._get_val(self._current_message.num_sv)

  @property
  def fix_type_string(self):
    fix_type = self.fix_type
    if fix_type is not _DEFAULT_VAL:
      if fix_type == MipGnssFixInfo.FIX_TYPE_FIX_3D:
        return "3D Fix (%d)" % fix_type
      elif fix_type == MipGnssFixInfo.FIX_TYPE_FIX_2D:
        return "2D Fix (%d)" % fix_type
      elif fix_type == MipGnssFixInfo.FIX_TYPE_FIX_TIME_ONLY:
        return "Time Only (%d)" % fix_type
      elif fix_type == MipGnssFixInfo.FIX_TYPE_FIX_NONE:
        return "None (%d)" % fix_type
      elif fix_type == MipGnssFixInfo.FIX_TYPE_FIX_INVALID:
        return "Invalid Fix (%d)" % fix_type
      elif fix_type == MipGnssFixInfo.FIX_TYPE_FIX_RTK_FLOAT:
        return "RTK Float (%d)" % fix_type
      elif fix_type == MipGnssFixInfo.FIX_TYPE_FIX_RTK_FIXED:
        return "RTK Fixed (%d)" % fix_type
      else:
        return "Invalid (%d)" % fix_type
    else:
      return _DEFAULT_STR

  @property
  def num_sv_string(self):
    return self._get_string(self.num_sv)

class FilterStatusMonitor(SubscriberMonitor):

  def __init__(self, node, node_name, topic_name, device_report_monitor):
    super(FilterStatusMonitor, self).__init__(node, node_name, topic_name, HumanReadableStatus)

    # Save a copy of the device report monitor
    self._device_report_monitor = device_report_monitor
  
  @property
  def filter_state_string(self):
    return self._get_val(self._current_message.filter_state)

  @property
  def status_flags_string(self):
    return self._get_val(','.join(self._current_message.status_flags))

class OdomMonitor(SubscriberMonitor):

  _MIN_COVARIANCE_SIZE = 36

  def __init__(self, node, node_name, topic_name, llh=True):
    super(OdomMonitor, self).__init__(node, node_name, topic_name, Odometry, callback=self._callback)

    # Use different units if we are using LLH versus ECEF
    if llh:
      self._xy_units = _UNIT_DEGREES
    else:
      self._xy_units = _UNIT_METERS

    # Initialize some member variables
    self._current_roll = _DEFAULT_VAL
    self._current_pitch = _DEFAULT_VAL
    self._current_yaw = _DEFAULT_VAL

  def _callback(self, status_message):
    quaternion = [self._current_message.pose.pose.orientation.x, self._current_message.pose.pose.orientation.y, self._current_message.pose.pose.orientation.z, self._current_message.pose.pose.orientation.w]
    self._current_roll, self._current_pitch, self._current_yaw = self._euler_from_quaternion(quaternion)
    super(OdomMonitor, self)._default_callback(status_message)

  @property
  def position_x(self):
    return self._get_val(self._current_message.pose.pose.position.x)

  @property
  def position_y(self):
    return self._get_val(self._current_message.pose.pose.position.y)

  @property
  def position_z(self):
    return self._get_val(self._current_message.pose.pose.position.z)

  @property
  def position_uncertainty_x(self):
    if len(self._current_message.pose.covariance) >= self._MIN_COVARIANCE_SIZE:
      return self._get_val(math.sqrt(self._current_message.pose.covariance[0]))
    else:
      return _DEFAULT_VAL

  @property
  def position_uncertainty_y(self):
    if len(self._current_message.pose.covariance) >= self._MIN_COVARIANCE_SIZE:
      return self._get_val(math.sqrt(self._current_message.pose.covariance[7]))
    else:
      return _DEFAULT_VAL

  @property
  def position_uncertainty_z(self):
    if len(self._current_message.pose.covariance) >= self._MIN_COVARIANCE_SIZE:
      return self._get_val(math.sqrt(self._current_message.pose.covariance[14]))
    else:
      return _DEFAULT_VAL

  @property
  def orientation_x(self):
    return self._get_val(self._current_roll)

  @property
  def orientation_y(self):
    return self._get_val(self._current_pitch)

  @property
  def orientation_z(self):
    return self._get_val(self._current_yaw)
  
  @property
  def orientation_uncertainty_x(self):
    if len(self._current_message.pose.covariance) >= self._MIN_COVARIANCE_SIZE:
      return self._get_val(math.sqrt(self._current_message.pose.covariance[21]))
    else:
      return _DEFAULT_VAL

  @property
  def orientation_uncertainty_y(self):
    if len(self._current_message.pose.covariance) >= self._MIN_COVARIANCE_SIZE:
      return self._get_val(math.sqrt(self._current_message.pose.covariance[28]))
    else:
      return _DEFAULT_VAL

  @property
  def orientation_uncertainty_z(self):
    if len(self._current_message.pose.covariance) >= self._MIN_COVARIANCE_SIZE:
      return self._get_val(math.sqrt(self._current_message.pose.covariance[35]))
    else:
      return _DEFAULT_VAL

  @property
  def velocity_x(self):
    return self._get_val(self._current_message.twist.twist.linear.x)

  @property
  def velocity_y(self):
    return self._get_val(self._current_message.twist.twist.linear.y)

  @property
  def velocity_z(self):
    return self._get_val(self._current_message.twist.twist.linear.z)
  
  @property
  def velocity_uncertainty_x(self):
    if len(self._current_message.twist.covariance) >= self._MIN_COVARIANCE_SIZE:
      return self._get_val(math.sqrt(self._current_message.twist.covariance[0]))
    else:
      return _DEFAULT_VAL

  @property
  def velocity_uncertainty_y(self):
    if len(self._current_message.twist.covariance) >= self._MIN_COVARIANCE_SIZE:
      return self._get_val(math.sqrt(self._current_message.twist.covariance[7]))
    else:
      return _DEFAULT_VAL

  @property
  def velocity_uncertainty_z(self):
    if len(self._current_message.twist.covariance) >= self._MIN_COVARIANCE_SIZE:
      return self._get_val(math.sqrt(self._current_message.twist.covariance[14]))
    else:
      return _DEFAULT_VAL

  @property
  def position_x_string(self):
    return self._get_string_units(self.position_x, self._xy_units)

  @property
  def position_y_string(self):
    return self._get_string_units(self.position_y, self._xy_units)

  @property
  def position_z_string(self):
    return self._get_string_units(self.position_x, _UNIT_METERS)

  @property
  def position_uncertainty_x_string(self):
    return self._get_string_units(self.position_uncertainty_x, _UNIT_METERS)

  @property
  def position_uncertainty_y_string(self):
    return self._get_string_units(self.position_uncertainty_y, _UNIT_METERS)

  @property
  def position_uncertainty_z_string(self):
    return self._get_string_units(self.position_uncertainty_z, _UNIT_METERS)

  @property
  def orientation_x_string(self):
    return self._get_string_units(self.orientation_x, _UNIT_RADIANS)

  @property
  def orientation_y_string(self):
    return self._get_string_units(self.orientation_y, _UNIT_RADIANS)

  @property
  def orientation_z_string(self):
    return self._get_string_units(self.orientation_z, _UNIT_RADIANS)

  @property
  def orientation_uncertainty_x_string(self):
    return self._get_string_units(self.orientation_uncertainty_x, _UNIT_RADIANS)

  @property
  def orientation_uncertainty_y_string(self):
    return self._get_string_units(self.orientation_uncertainty_y, _UNIT_RADIANS)

  @property
  def orientation_uncertainty_z_string(self):
    return self._get_string_units(self.orientation_uncertainty_z, _UNIT_RADIANS)

  @property
  def velocity_x_string(self):
    return self._get_string_units(self.velocity_x, _UNIT_METERS_PER_SEC)

  @property
  def velocity_y_string(self):
    return self._get_string_units(self.velocity_y, _UNIT_METERS_PER_SEC)

  @property
  def velocity_z_string(self):
    return self._get_string_units(self.velocity_z, _UNIT_METERS_PER_SEC)

  @property
  def velocity_uncertainty_x_string(self):
    return self._get_string_units(self.velocity_uncertainty_x, _UNIT_METERS_PER_SEC)

  @property
  def velocity_uncertainty_y_string(self):
    return self._get_string_units(self.velocity_uncertainty_y, _UNIT_METERS_PER_SEC)

  @property
  def velocity_uncertainty_z_string(self):
    return self._get_string_units(self.velocity_uncertainty_z, _UNIT_METERS_PER_SEC)


class GNSSDualAntennaStatusMonitor(SubscriberMonitor):

  def __init__(self, node, node_name, topic_name):
    super(GNSSDualAntennaStatusMonitor, self).__init__(node, node_name, topic_name, MipFilterGnssDualAntennaStatus)
  
  @property
  def fix_type(self):
    return self._get_val(self._current_message.fix_type)

  @property
  def heading(self):
    return self._get_val(self._current_message.heading)

  @property
  def heading_uncertainty(self):
    return self._get_val(self._current_message.heading_unc)
  
  @property
  def rec_1_data_valid(self):
    return bool(self._get_val(self._current_message.status_flags.rcv_1_valid))

  @property
  def rec_2_data_valid(self):
    return bool(self._get_val(self._current_message.status_flags.rcv_2_valid))
  
  @property
  def antenna_offsets_valid(self):
    return bool(self._get_val(self._current_message.status_flags.antenna_offsets_valid))

  @property
  def fix_type_string(self):
    fix_type = self.fix_type
    if fix_type is not _DEFAULT_VAL:
      if fix_type == MipFilterGnssDualAntennaStatus.FIX_TYPE_FIX_NONE:
        return "None (%d)" % fix_type
      elif fix_type == MipFilterGnssDualAntennaStatus.FIX_TYPE_FIX_DA_FLOAT:
        return "Float (%d)" % fix_type
      elif fix_type == MipFilterGnssDualAntennaStatus.FIX_TYPE_FIX_DA_FIXED:
        return "Fixed (%d)" % fix_type
      else:
        return _DEFAULT_STR
    else:
      return _DEFAULT_STR
  
  @property
  def heading_string(self):
    return self._get_string_units(self.heading, _UNIT_RADIANS)

  @property
  def heading_uncertainty_string(self):
    return self._get_string_units(self.heading_unc, _UNIT_RADIANS)

  @property
  def rec_1_data_valid_string(self):
    return self._get_small_boolean_icon_string(self.rec_1_data_valid)

  @property
  def rec_2_data_valid_string(self):
    return self._get_small_boolean_icon_string(self.rec_2_data_valid)

  @property
  def antenna_offsets_valid_string(self):
    return self._get_small_boolean_icon_string(self.antenna_offsets_valid)


class ImuMonitor(SubscriberMonitor):

  def __init__(self, node, node_name, topic_name):
    super(ImuMonitor, self).__init__(node, node_name, topic_name, Imu)

  @property
  def accel_x(self):
    return self._get_val(self._current_message.linear_acceleration.x)
  
  @property
  def accel_y(self):
    return self._get_val(self._current_message.linear_acceleration.y)
  
  @property
  def accel_z(self):
    return self._get_val(self._current_message.linear_acceleration.z)
  
  @property
  def vel_x(self):
    return self._get_val(self._current_message.angular_velocity.x)
  
  @property
  def vel_y(self):
    return self._get_val(self._current_message.angular_velocity.y)
  
  @property
  def vel_z(self):
    return self._get_val(self._current_message.angular_velocity.z)

  @property
  def accel_x_string(self):
    return self._get_string_units(self.accel_x, _UNIT_GS)

  @property
  def accel_y_string(self):
    return self._get_string_units(self.accel_y, _UNIT_GS)

  @property
  def accel_z_string(self):
    return self._get_string_units(self.accel_z, _UNIT_GS)

  @property
  def vel_x_string(self):
    return self._get_string_units(self.vel_x, _UNIT_RADIANS_PER_SEC)

  @property
  def vel_y_string(self):
    return self._get_string_units(self.vel_y, _UNIT_RADIANS_PER_SEC)

  @property
  def vel_z_string(self):
    return self._get_string_units(self.vel_z, _UNIT_RADIANS_PER_SEC)


class MagMonitor(SubscriberMonitor):

  def __init__(self, node, node_name, topic_name):
    super(MagMonitor, self).__init__(node, node_name, topic_name, MagneticField)
  
  @property
  def x(self):
    return self._get_val(self._current_message.magnetic_field.x)

  @property
  def y(self):
    return self._get_val(self._current_message.magnetic_field.y)

  @property
  def z(self):
    return self._get_val(self._current_message.magnetic_field.z)

  @property
  def x_string(self):
    return self._get_string_units(self.x, _UNIT_GUASSIAN)

  @property
  def y_string(self):
    return self._get_string_units(self.y, _UNIT_GUASSIAN)

  @property
  def z_string(self):
    return self._get_string_units(self.z, _UNIT_GUASSIAN)


class NavSatFixMonitor(SubscriberMonitor):

  _MIN_COVARIANCE_SIZE = 9

  def __init__(self, node, node_name, topic_name):
    super(NavSatFixMonitor, self).__init__(node, node_name, topic_name, NavSatFix)

  @property
  def position_uncertainty(self):
    if len(self._current_message.position_covariance) >= self._MIN_COVARIANCE_SIZE:
      return self._get_val(math.sqrt(self._current_message.position_covariance[0]))
    else:
      return _DEFAULT_VAL
  
  @property
  def position_uncertainty_string(self):
    return self._get_string_units(self.position_uncertainty, _UNIT_METERS)


# TODO: This should be one class
class RTKMonitorBase(SubscriberMonitor):

  def __init__(self, node, node_name, topic_name, message_type):
    super(RTKMonitorBase, self).__init__(node, node_name, topic_name, message_type)

  @property
  def gps_received(self):
    return self._get_val(self._current_message.epoch_status.gps_received)

  @property
  def glonass_received(self):
    return self._get_val(self._current_message.epoch_status.glonass_received)

  @property
  def galileo_received(self):
    return self._get_val(self._current_message.epoch_status.galileo_received)

  @property
  def beidou_received(self):
    return self._get_val(self._current_message.epoch_status.beidou_received)
  
  @property
  def version(self):
    return 2

  @property
  def raw_status_flags(self):
    return 0

  @property
  def signal_quality(self):
    return self._get_val(self._current_message.dongle_status.signal_quality)

  @property
  def gps_received_string(self):
    return self._get_small_boolean_icon_string(self.gps_received)

  @property
  def glonass_received_string(self):
    return self._get_small_boolean_icon_string(self.glonass_received)

  @property
  def galileo_received_string(self):
    return self._get_small_boolean_icon_string(self.galileo_received)

  @property
  def beidou_received_string(self):
    return self._get_small_boolean_icon_string(self.beidou_received)

  @property
  def version_string(self):
    return self._get_string(self.version)

  @property
  def raw_status_flags_string(self):
    return self._get_string_hex(self.raw_status_flags)

  @property
  def signal_quality_string(self):
    return self._get_string(self.signal_quality)
  
  @property
  def rtk_led_string(self):
    pass


class RTKMonitor(RTKMonitorBase):

  def __init__(self, node, node_name, topic_name):
    super(RTKMonitor, self).__init__(node, node_name, topic_name, MipGnssCorrectionsRtkCorrectionsStatus)

  @property
  def modem_state(self):
    return self._get_val(self._current_message.dongle_status.modem_state)

  @property
  def connection_type(self):
    return self._get_val(self._current_message.dongle_status.connection_type)

  @property
  def rssi(self):
    rssi = self._current_message.dongle_status.rssi
    if rssi is not _DEFAULT_VAL:
      return -rssi
    else:
      return _DEFAULT_VAL

  @property
  def tower_change_indicator(self):
    return self._get_val(self._current_message.dongle_status.tower_change_indicator)

  @property
  def nmea_timeout(self):
    return self._get_val(self._current_message.dongle_status.nmea_timeout_flag)

  @property
  def server_timeout(self):
    return self._get_val(self._current_message.dongle_status.server_timeout_flag)

  @property
  def rtcm_timeout(self):
    return self._get_val(self._current_message.dongle_status.rtcm_timeout_flag)

  @property
  def out_of_range(self):
    return self._get_val(self._current_message.dongle_status.device_out_of_range_flag)

  @property
  def corrections_unavailable(self):
    return self._get_val(self._current_message.dongle_status.corrections_unavailable_flag)

  @property
  def modem_state_string(self):
    modem_state = self.modem_state
    if modem_state is not _DEFAULT_VAL:
      if modem_state == self._current_message.dongle_status.MODEM_STATE_OFF:
        return "Off (%d)" % modem_state
      elif modem_state == self._current_message.dongle_status.MODEM_STATE_NO_NETWORK:
        return "No Network (%d)" % modem_state
      elif modem_state == self._current_message.dongle_status.MODEM_STATE_NETWORK_CONNECTED:
        return "Connected (%d)" % modem_state
      elif modem_state == self._current_message.dongle_status.MODEM_STATE_CONFIGURING_DATA_CONTEXT:
        return "Configuring Data Context (%d)" % modem_state
      elif modem_state == self._current_message.dongle_status.MODEM_STATE_ACTIVATING_DATA_CONTEXT:
        return "Activating Data Context (%d)" % modem_state
      elif modem_state == self._current_message.dongle_status.MODEM_STATE_CONFIGURING_SOCKET:
        return "Configuring Socket (%d)" % modem_state
      elif modem_state == self._current_message.dongle_status.MODEM_STATE_WAITING_ON_SERVER_HANDSHAKE:
        return "Waiting on Server Handshake (%d)" % modem_state
      elif modem_state == self._current_message.dongle_status.MODEM_STATE_CONNECTED_AND_IDLE:
        return "Connected & Idle (%d)" % modem_state
      elif modem_state == self._current_message.dongle_status.MODEM_STATE_CONNECTED_AND_STREAMING:
        return "Connected & Streaming (%d)" % modem_state
      else:
        return "Invalid (%d)" % modem_state
    else:
      return _DEFAULT_STR

  @property
  def connection_type_string(self):
    connection_type = self.connection_type
    if connection_type is not _DEFAULT_VAL:
      if connection_type == self._current_message.dongle_status.CONNECTION_TYPE_NO_CONNECTION:
        return "No Connection (%d)" % connection_type
      elif connection_type == self._current_message.dongle_status.CONNECTION_TYPE_CONNECTION_2G:
        return "2G (%d)" % connection_type
      elif connection_type == self._current_message.dongle_status.CONNECTION_TYPE_CONNECTION_3G:
        return "3G (%d)" % connection_type
      elif connection_type == self._current_message.dongle_status.CONNECTION_TYPE_CONNECTION_4G:
        return "4G (%d)" % connection_type
      elif connection_type == self._current_message.dongle_status.CONNECTION_TYPE_CONNECTION_5G:
        return "5G (%d)" % connection_type
      else:
        return "Invalid (%d)" % connection_type
    else:
      return _DEFAULT_STR

  @property
  def rssi_string(self):
    return self._get_string(self.rssi)

  @property
  def tower_change_indicator_string(self):
    return self._get_string(self.tower_change_indicator)

  @property
  def nmea_timeout_string(self):
    return self._get_boolean_string(self.nmea_timeout)

  @property
  def server_timeout_string(self):
    return self._get_boolean_string(self.server_timeout)

  @property
  def rtcm_timeout_string(self):
    return self._get_boolean_string(self.rtcm_timeout)

  @property
  def out_of_range_string(self):
    return self._get_boolean_string(self.out_of_range)

  @property
  def corrections_unavailable_string(self):
    return self._get_boolean_string(self.corrections_unavailable)

  @property
  def rtk_led_string(self):
    modem_state = self.modem_state
    if modem_state is not _DEFAULT_VAL:      
      if modem_state == self._current_message.dongle_status.MODEM_STATE_NO_NETWORK:
        return _ICON_YELLOW_UNCHECKED_MEDIUM
      elif modem_state == self._current_message.dongle_status.MODEM_STATE_NETWORK_CONNECTED:
        return _ICON_GREEN_CHECKED_MEDIUM
      elif modem_state == self._current_message.dongle_status.MODEM_STATE_CONFIGURING_DATA_CONTEXT:
        return _ICON_GREEN_CHECKED_MEDIUM
      elif modem_state == self._current_message.dongle_status.MODEM_STATE_ACTIVATING_DATA_CONTEXT:
        return _ICON_GREEN_CHECKED_MEDIUM
      elif modem_state == self._current_message.dongle_status.MODEM_STATE_CONFIGURING_SOCKET:
        return _ICON_GREEN_CHECKED_MEDIUM
      elif modem_state == self._current_message.dongle_status.MODEM_STATE_WAITING_ON_SERVER_HANDSHAKE:
        return _ICON_GREEN_CHECKED_MEDIUM
      elif modem_state == self._current_message.dongle_status.MODEM_STATE_CONNECTED_AND_IDLE:
        return _ICON_BLUE_CHECKED_MEDIUM
      elif modem_state == self._current_message.dongle_status.MODEM_STATE_CONNECTED_AND_STREAMING:
        return _ICON_BLUE_CHECKED_MEDIUM
    else:
      return _ICON_GREY_UNCHECKED_MEDIUM

class FilterAidingMeasurementSummaryIndicatorMonitor(SubscriberMonitor):
  def __init__(self, node, node_name, topic_name):
    super(FilterAidingMeasurementSummaryIndicatorMonitor, self).__init__(node, node_name, topic_name, MipFilterAidingMeasurementSummary)

  @property
  def source(self):
    return self._get_val(self._current_message.source)
  
  @property
  def type(self):
    return self._get_val(self._current_message.type)
  
  @property
  def enabled(self):
    return self._get_val(self._current_message.indicator.enabled)

  @property
  def used(self):
    return self._get_val(self._current_message.indicator.used)
  
  @property
  def residual_high_warning(self):
    return self._get_val(self._current_message.indicator.residual_high_warning)

  @property
  def sample_time_warning(self):
    return self._get_val(self._current_message.indicator.sample_time_warning)
  
  @property
  def configuration_error(self):
    return self._get_val(self._current_message.indicator.configuration_error)
  
  @property
  def max_num_meas_exceeded(self):
    return self._get_val(self._current_message.indicator.max_num_meas_exceeded)

class FilterAidingMeasurementSummaryMonitor(SubscriberMonitor):

  def __init__(self, node, node_name, topic_name):
    super(FilterAidingMeasurementSummaryMonitor, self).__init__(node, node_name, topic_name, MipFilterAidingMeasurementSummary, callback=self._on_message)

  def _on_message(self, message):
    pass

  @property
  def gnss1_enabled(self):
    return self._get_val(self._current_message.gnss1.enabled)

  @property
  def gnss1_used(self):
    return self._get_val(self._current_message.gnss1.used)

  @property
  def gnss2_enabled(self):
    return self._get_val(self._current_message.gnss2.enabled)

  @property
  def gnss2_used(self):
    return self._get_val(self._current_message.gnss2.used)

  @property
  def dual_antenna_enabled(self):
    return self._get_val(self._current_message.dual_antenna.enabled)

  @property
  def dual_antenna_used(self):
    return self._get_val(self._current_message.dual_antenna.used)

  @property
  def heading_enabled(self):
    return self._get_val(self._current_message.heading.enabled)

  @property
  def heading_used(self):
    return self._get_val(self._current_message.heading.used)

  @property
  def pressure_enabled(self):
    return self._get_val(self._current_message.pressure.enabled)

  @property
  def pressure_used(self):
    return self._get_val(self._current_message.pressure.used)

  @property
  def magnetometer_enabled(self):
    return self._get_val(self._current_message.magnetometer.enabled)

  @property
  def magnetometer_used(self):
    return self._get_val(self._current_message.magnetometer.used)

  @property
  def speed_enabled(self):
    return self._get_val(self._current_message.speed.enabled)

  @property
  def speed_used(self):
    return self._get_val(self._current_message.speed.used)

  @property
  def gnss1_enabled_string(self):
    return self._get_small_boolean_icon_string(self.gnss1_enabled)

  @property
  def gnss1_used_string(self):
    return self._get_small_boolean_icon_string(self.gnss1_used)

  @property
  def gnss2_enabled_string(self):
    return self._get_small_boolean_icon_string(self.gnss2_enabled)

  @property
  def gnss2_used_string(self):
    return self._get_small_boolean_icon_string(self.gnss2_used)

  @property
  def dual_antenna_enabled_string(self):
    return self._get_small_boolean_icon_string(self.dual_antenna_enabled)

  @property
  def dual_antenna_used_string(self):
    return self._get_small_boolean_icon_string(self.dual_antenna_used)

  @property
  def heading_enabled_string(self):
    return self._get_small_boolean_icon_string(self.heading_enabled)

  @property
  def heading_used_string(self):
    return self._get_small_boolean_icon_string(self.heading_used)

  @property
  def pressure_enabled_string(self):
    return self._get_small_boolean_icon_string(self.pressure_enabled)

  @property
  def pressure_used_string(self):
    return self._get_small_boolean_icon_string(self.pressure_used)

  @property
  def magnetometer_enabled_string(self):
    return self._get_small_boolean_icon_string(self.magnetometer_enabled)

  @property
  def magnetometer_used_string(self):
    return self._get_small_boolean_icon_string(self.magnetometer_used)

  @property
  def speed_enabled_string(self):
    return self._get_small_boolean_icon_string(self.speed_enabled)

  @property
  def speed_used_string(self):
    return self._get_small_boolean_icon_string(self.speed_used)


class GQ7LedMonitor:
  def __init__(self, filter_status_monitor, gnss_1_aiding_status_monitor, gnss_2_aiding_status_monitor):
    # This monitor is a little different in that it checks other monitors, so just save the other monitors
    self._filter_status_monitor = filter_status_monitor
    self._gnss_1_aiding_status_monitor = gnss_1_aiding_status_monitor
    self._gnss_2_aiding_status_monitor = gnss_2_aiding_status_monitor

  @property
  def gq7_led_icon(self):
    filter_state = self._filter_status_monitor.filter_state_string
    if filter_state is not _DEFAULT_VAL:
      if filter_state == HumanReadableStatus.FILTER_STATE_GQ7_INIT:
        return _ICON_YELLOW_CHECKED_MEDIUM
      elif filter_state == HumanReadableStatus.FILTER_STATE_GQ7_VERT_GYRO or filter_state == HumanReadableStatus.FILTER_STATE_GQ7_AHRS:
        return _ICON_YELLOW_UNCHECKED_MEDIUM
      elif filter_state == HumanReadableStatus.FILTER_STATE_GQ7_FULL_NAV:
        gnss_1_differential = self._gnss_1_aiding_status_monitor.differential_corrections
        gnss_2_differential = self._gnss_2_aiding_status_monitor.differential_corrections
        if (gnss_1_differential is not _DEFAULT_VAL and gnss_1_differential) or (gnss_2_differential is not _DEFAULT_VAL and gnss_2_differential):
          return _ICON_BLUE_CHECKED_MEDIUM
        else:
          return _ICON_GREEN_CHECKED_MEDIUM
    else:
      return _ICON_GREY_UNCHECKED_MEDIUM