function linear_exponential

clear all; close all;

tau = 0.2;

s=tf('s');
G=1/(tau*s+1);

Vfc=1;
Ps=[2 2];
Pe=[10 10];
[xs,ys] = deal(Ps(1),Ps(2));
[xe,ye] = deal(Pe(1),Pe(2));
thetaL = atan((ye-ys)/(xe-xs));
Ld=sqrt((xe-xs)^2+(ye-ys)^2);
tauE=Ld/Vfc;
t=0:0.2:tauE;
gtau=Vfc*t;
I=ones(1,size(t,2));

xi=gtau*cos(thetaL)+xs;
yi=gtau*sin(thetaL)+ys;

vx=@(t) Vfc*cos(thetaL)*I;
vy=@(t) Vfc*sin(thetaL)*I;

    function v = velocity(t)
        v = sqrt(vx(t).^2+vy(t).^2);
    end


subplot(3,2,1);
hold on;
plot(xs,ys,'ko');
plot(xe,ye,'ko');
plot(xi,yi,'bo');
xlabel('x');
ylabel('y');
title('position');

subplot(3,2,3);
hold on;
plot(t,velocity(t),'b-');
xlabel('time[sec]');
ylabel('velocity[m/s]');
title('velocity');

subplot(3,2,5);
hold on;
accel=diff(velocity(t))./diff(t)
plot(t(1:end-1),accel,'b-');
xlabel('time[sec]');
ylabel('acceleration[m2/sec]');
title('accel');

subplot(3,2,2);
hold on;
plot(xs,ys,'ko');
plot(xe,ye,'ko');
plot(xi,yi,'bo');
xlabel('x');
ylabel('y');
title('position [filtered]');

subplot(3,2,4);
hold on;
plot(t,sin(t));
xlabel('time[sec]');
ylabel('velocity[m/s]');
title('velocity [filtered]');

subplot(3,2,6);
hold on;
plot(t,sin(t));
xlabel('time[sec]');
ylabel('acceleration[m2/sec]');
title('acceleration [filtered]');

set(gcf, 'name', 'Linear Interpolation & Exponential acceleration');
set(gcf, 'Position', [100, 100, 1000, 700]);


end