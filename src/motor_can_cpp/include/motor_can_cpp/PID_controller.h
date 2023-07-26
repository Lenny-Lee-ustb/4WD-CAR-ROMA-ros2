class PIDController {
public:
    PIDController()
        : kp_(0), ki_(0), kd_(0), dt_(0), integral_(0), prev_error_(0) {}

    void setPID(double kp, double ki, double kd, double int_bound,double dt) {
        kp_ = kp;
        ki_ = ki;
        kd_ = kd;
        integral_bound_ = int_bound;
        dt_ = dt;
    }

    void reset() {
        integral_ = 0;
        prev_error_ = 0;
    }

    double calculateOutput(double setpoint, double current_value) {
        double error = setpoint - current_value;
        integral_ += error * dt_;
        integral_ = std::min(std::max(integral_, -integral_bound_), integral_bound_);
        double derivative = (error - prev_error_) / dt_;
        prev_error_ = error;

        double output = kp_ * error + ki_ * integral_ + kd_ * derivative;
        return output;
    }

private:
    double kp_;        // Proportional gain
    double ki_;        // Integral gain
    double kd_;        // Derivative gain
    double dt_;        // Time step (sampling time)
    double integral_;  // Integral term accumulation
    double integral_bound_;
    double prev_error_; // Previous error for derivative term
};