from .utils.widgets import MicrostrainWidget, MicrostrainPlugin
from .utils.subscribers import RTKMonitor

_WIDGET_NAME = 'RTKStatus'

class RTKStatusWidget(MicrostrainWidget):

  def __init__(self, node):
    # Initialize the parent class
    super(RTKStatusWidget, self).__init__(node, _WIDGET_NAME)

  def _configure(self):
    # Set up the subscriber status monitors
    self._rtk_status_monitor = RTKMonitor(self._node, self._node_name, "rtk/status")

    # Hide the warning label
    self.rtk_not_available_label.hide()

  def run(self):
    # If the device is connected and not a GQ7, display a warning
    if self._device_report_monitor.connected and not self._device_report_monitor.is_gq7:
      self.rtk_widget.hide()
      self.rtk_not_available_label.setText('RTK status only available for GQ7 devices. Not available for device %s' % self._device_report_monitor.model_name_string)
      self.rtk_not_available_label.show()
      return
    else:
      self.rtk_not_available_label.hide()
      self.rtk_widget.show()

    # Update device specific data
    self._update_rtk_data_v2()
    
  def _update_rtk_data_v2(self):
    # V2 Status Flags
    self.rtk_status_flags_modem_state_label.setText(self._rtk_status_monitor.modem_state_string)
    self.rtk_status_flags_connection_type_label.setText(self._rtk_status_monitor.connection_type_string)
    self.rtk_status_flags_rssi_label.setText(self._rtk_status_monitor.rssi_string)
    self.rtk_status_flags_tower_change_indicator_label.setText(self._rtk_status_monitor.tower_change_indicator_string)
    self.rtk_status_flags_nmea_timeout_label.setText(self._rtk_status_monitor.nmea_timeout_string)
    self.rtk_status_flags_server_timeout_label.setText(self._rtk_status_monitor.server_timeout_string)
    self.rtk_status_flags_rtcm_timeout_label.setText(self._rtk_status_monitor.rtcm_timeout_string)
    self.rtk_status_flags_out_of_range_label.setText(self._rtk_status_monitor.out_of_range_string)
    self.rtk_status_flags_corrections_unavailable_label.setText(self._rtk_status_monitor.corrections_unavailable_string)

    # V1 Modem state icon label
    self.rtk_led_status_label.setText(self._rtk_status_monitor.modem_state_string)

    # Update common flags
    self._update_rtk_data(self._rtk_status_monitor)

  # TODO: Merge into one function
  def _update_rtk_data(self, rtk_monitor):
    # Epoch Status flags
    self.rtk_corrections_received_gps_label.setText(rtk_monitor.gps_received_string)
    self.rtk_corrections_received_glonass_label.setText(rtk_monitor.glonass_received_string)
    self.rtk_corrections_received_galileo_label.setText(rtk_monitor.galileo_received_string)
    self.rtk_corrections_received_beidou_label.setText(rtk_monitor.beidou_received_string)

    # Icon and label
    self.rtk_led_icon_label.setText(rtk_monitor.rtk_led_string)

    # Other flags
    self.rtk_raw_status_flag_label.setText(rtk_monitor.raw_status_flags_string)
    self.rtk_status_flags_signal_quality_label.setText(rtk_monitor.signal_quality_string)

class RTKStatusPlugin(MicrostrainPlugin):

  def __init__(self, context):
    # Initialize the parent class
    super(RTKStatusPlugin, self).__init__(context, _WIDGET_NAME, RTKStatusWidget)
