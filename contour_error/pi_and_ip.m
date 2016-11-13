clear all; close all;
m=1;Kvp=4;Kvi=1;

slkname='PI_and_I_P';

Kff=1;fbon1=0;fbon2=0;
[A B C D]=linmod(slkname);
sys=ss(A,B,C,D);
figure(1);
rlocus(sys(1,1));
hold on;

Kff=0;fbon1=1;fbon2=0;
[A B C D]=linmod(slkname);
sys=ss(A,B,C,D);
figure(2);
rlocus(sys(1,1));
hold on;

