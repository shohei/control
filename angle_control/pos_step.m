close all;
clear all;

sim_init();
load sim_param;

r=60;
r_cyc=8;
Kp_id=0.12;
Ncyc=2;
tfinal = r_cyc*Ncyc;

simset('SrcWorkspace','current');

open_system('pos_step_sl');
open_system('pos_step_sl/Scope');

set_param('pos_step_sl','SimulationCommand','start');

y=ScopeData.signals(1).values(:,2);
t=ScopeData.time;

NN=length(y);
N=r_cyc/ts;

yy=reshape(y(2:NN),N,(NN-1)/N);
yf=yy(1:N/2,2:end);

ym=mean(yf')';
y0=ym(1);
yN=ym(end);
y=(ym-y0)/(yN-y0);

t=(0:N/2-1)*ts;
figure(1);
subplot(211);
plot(t,yf)
grid;
xlabel('Time [s]');
ylabel('Output [deg]');
subplot(212);
plot(t,ym);
grid;
xlabel('Time [s]');
ylabel('Output [deg]');

