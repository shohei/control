function exponential_accel

clear all; close all;

t=linspace(0,2,21);
tau = 0.2;

s=tf('s');
G=1/(tau*s+1);




subplot(3,2,1);
plot(t,sin(t));
xlabel('time[sec]');
ylabel('position');
title('position');

subplot(3,2,3);
plot(t,sin(t));
xlabel('time[sec]');
ylabel('velocity[m/s]');
title('velocity');

subplot(3,2,5);
plot(t,sin(t));
xlabel('time[sec]');
ylabel('acceleration[m2/sec]');
title('accel');

subplot(3,2,2);
plot(t,sin(t));
xlabel('time[sec]');
ylabel('position');
title('position [filtered]');

subplot(3,2,4);
plot(t,sin(t));
xlabel('time[sec]');
ylabel('velocity[m/s]');
title('velocity [filtered]');

subplot(3,2,6);
plot(t,sin(t));
xlabel('time[sec]');
ylabel('acceleration[m2/sec]');
title('acceleration [filtered]');

set(gcf, 'name', 'Exponential acceleration');
set(gcf, 'Position', [100, 100, 1000, 700]);


end