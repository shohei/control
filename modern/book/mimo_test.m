function mimo_test

clear all;
close all;

A=[
  0 1 0 0
  -2 -2 1 2
  0 0 0 1
  2 2 -2 -8
];

B = [
  0 0 
  2 -2
  0 0
  -2 4
];

C = [
  1 0 0 0    
  0 0 1 0
];

D = [
  0 0 
  0 0
];

sys = ss(A,B,C,D);

t= 0:0.01:20;

x0 = [1 0 -1 0]';

y=initial(sys,x0,t);
y1=y(:,1);
y2=y(:,2);
subplot(3,1,1)
hold on;
plot(t,y1);
plot(t,y2);
grid on;
title('Zero input response(MIMO)')

subplot(3,1,2)
y=step(sys,t);
y1=y(:,1);
y2=y(:,2);
hold on;
plot(t,y1);
plot(t,y2);
grid on;
title('Step response(MIMO)')

subplot(3,1,3)
u= [ones(size(t))
   ones(size(t))];  
y=lsim(sys,u,t,x0);
y1=y(:,1);
y2=y(:,2);
hold on;
plot(t,y1);
plot(t,y2);
grid on;
title('Time response(MIMO)')



end