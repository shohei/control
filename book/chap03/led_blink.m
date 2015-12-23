%% led_blink.m
a = arduino('COM3');
a.pinMode(11,'output');
for i=1:10
  a.digitalWrite(11,1);
  pause(1);
  a.digitalWrite(11,0);
  pause(1);
end
delete(a);