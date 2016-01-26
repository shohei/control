function basic
clear all; close all;
hold on;

% a = 2;
theta = linspace(0,2*pi,101);
I = ones(1,length(theta));
% r = a*I;

% p = polar(theta,r);
% h = findall(gcf,'type','line');
% h(h == p) = [];
% delete(h);
% xlim([-5 5]);
% ylim([-5 5]);
x1=1;
y1=2;
x2=3;
y2=4;
plot(x1,y1,'bo');
plot(x2,y2,'bo');

r1 = sqrt(x1^2+y1^2);
theta1 = atan(y1/x1);
r2 = sqrt(x2^2+y2^2);
theta2 = atan(y2/x2);

theta = linspace(theta1,theta2,101);
r = r1*r2*sin(theta1-theta2)./(r1*sin(theta1-theta)+r2*sin(theta-theta2));
polar(theta,r);

xmax=5;
ymax=5;
plot([0 0],[-ymax ymax],'k--');
plot([-xmax xmax],[0,0],'k--');
axis equal;
xlim([-xmax xmax]);
ylim([-ymax ymax]);


end