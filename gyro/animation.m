function animation
clear; close all;

r = [1,1,1];       % Reference position
A = [0, 0, 0]; % Reference orientation (x-y-z Euler angle)
% drawDisc(r,A)
hold on;
global h1; global h2; global h3;
global h4; global h5;

for t=1:100
%    A=[-pi/10*t, 0, 0];
   delete(h1);
   delete(h2);
   delete(h3);  
   delete(h4);  
   delete(h5);     
   A=[0, 0, pi/10*t];
   [h1,h2,h3,h4,h5]=drawDisc(r,A);  
   drawnow;
   t
end
    


end