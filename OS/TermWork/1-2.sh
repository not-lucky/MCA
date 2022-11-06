echo "Shell script to calculate the final velocity using formula v = u + (a * t)."

echo "Enter the initial velocity (in meters): "
read u
echo "Enter the acceleration (in meter/second^2): "
read a
echo "Enter the time duration (in seconds): "
read t

echo "The final velocity is (in meter/second): $((u + a * t)) m/s."
