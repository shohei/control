function ex_expm

clear all;
close all;

A=[
    0 1
    -10 -2
    ];

c=[1 0];
x0 = [1 0]';

ts = 0:0.1:5;
for idx=1:length(ts)
    t=ts(idx);
    y(idx) = c*expm(A*t)*x0;
end

plot(ts,y);



end
