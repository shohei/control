function sim_init

close all;
clear all;

ts=1/50;
s=tf('s');

Kp=0;
Ki=0;
Kd=0;

r=60;
r_cyc=4;
dist=0;
Ncyc=2;
tfinal = r_cyc*Ncyc;

save sim_param


end