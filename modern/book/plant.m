clear all;
format compact;

A = [0 1
    -10 -2];

B = [0 1]';

C=[1 0];

D=0;

sys=ss(A,B,C,D);

x0 = [1 0]';