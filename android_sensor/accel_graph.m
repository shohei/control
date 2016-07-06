function accel_graph

clear all;
close all;

m = mobiledev;
m.AccelerationSensorEnabled = 1;

m.Logging = 1;

figure();
hold on;
disp 'getting initialized...';
pause(2);

for idx = 1:20    
    [a, ta] = accellog(m);
    xa  = a(:,1);
    ya  = a(:,2);
    za  = a(:,3);
    
    plot(ta, xa,'r');
    plot(ta, ya,'b');
%     plot(ta, za,'g');
    
    drawnow;
    pause(1);    
end

m.Logging = 0;
m.AccelerationSensorEnabled = 0;

clear m;


end