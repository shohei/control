function animation
clear; close all;

% r = [0,0,1];       % Reference position
% A = [0, 0, 0]; % Reference orientation (x-y-z Euler angle)
% drawDisc(r,A)
hold on;
global h1; global h2; global h3;
global h4; global h5;
view([-37.5,30]);
r=1
for t=1:100
    %    A=[-pi/10*t, 0, 0];
    delete(h1);
    delete(h2);
    delete(h3);
    delete(h4);
    delete(h5);
    theta=pi/2*t;
    Omega=pi/4;
    omegaX=atan2(tan(Omega),sin(theta));
    omegaY=atan2(tan(Omega),cos(theta));
    A=[omegaX omegaY Omega];
    %    r = [cos(t/10),sin(t/10),1];
    rs = [r*sin(Omega)*cos(theta) r*sin(Omega)*sin(theta) r*cos(Omega)];
    [h1,h2,h3,h4,h5]=drawDisc(rs,A);
    drawnow;
    t
end


end