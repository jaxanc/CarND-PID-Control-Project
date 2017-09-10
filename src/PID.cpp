#include "PID.h"

using namespace std;

PID::PID() : 
  p_error(0),
  i_error(0),
  d_error(0),
  Kp(0),
  Ki(0),
  Kd(0),
  control(0),
  minOutput(0),
  maxOutput(0),
  totalError(0)
{}

PID::~PID() 
{}

void PID::Init(double Kp, double Ki, double Kd, double minOutput, double maxOutput)
{
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;

  i_error = 0;
  d_error = 0;
  p_error = 0;

  control = 0;
  totalError = 0;

  this->minOutput = minOutput;
  this->maxOutput = maxOutput;
}

double PID::UpdateError(double cte)
{
  d_error = cte - p_error;
  p_error = cte;

  double tempControl = Kp*p_error + Ki*(i_error + cte) + Kd*d_error;

  // anti-windup
  if ((tempControl >= minOutput) && (tempControl <= maxOutput))
  {
    i_error += cte;
  }
  else
  {
    // use previous i_error
  }

  control = Kp*p_error + Ki*i_error + Kd*d_error;

  // limit output
  if (control >= maxOutput)
  {
    control = maxOutput;
  }
  else if (control <= minOutput)
  {
    control = minOutput;
  }

  totalError += control;

  return control;
}

double PID::TotalError()
{
  return totalError;
}
