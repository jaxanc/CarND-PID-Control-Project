# Reflection

## Describe the effect each of the P, I, D components had in your implementation.

The proportional term changes the output (steering) proportional to the input (cte). The change is instantaneous and plays an important role for the car to rapidly respond to change. The side effect of this parameter is that it oscillates around the center line. The greater the cte is, the greater the steering angle. When car crosses the center line with high steering angle it will introduce high error on the next interation.

The integral term applies a change overtime. As described during the lecture, it is useful at correcting sensor drift. In this application of testing in the simulator. Sensor drift is zero, however it is used to keep the car closer to the center during a turn. This term lessen the need for proportional term which is more susceptable to oscillation.

The derivative term slows down the behavior of the controller and make it less susceptable to noise. This term reduces oscillation of the controller and introduces a much smoother controller behavior.

## Describe how the final hyperparameters were chosen.

The PID parameters are manually tuned. I started by implementing a basic throttle controller to reduce throttle proportional to steering. The default throttle started at 0.3 and increased to 0.75 as the steering controller was built.

The tuning started with proportional term only. However it was not enough. Every turn on the road causes the controller to oscillate more and more. 

I quickly introduced a large derivative term. This makes the controller good at staying in a straight line but less effect at making sharp terms.

The integral term was then implemented to better handle the sharp terms. The three parameters were then shifted up and down by monitoring the total error to balance the behavior between straight line and sharp turns.
