function identify(timestep)
ts=timestep;
simset('SrcWorkspace','current');
u_ini=2.0;
r_const=1.8;
p_const=2.5;
% Time may have to be less than 10sec!!!!!!!!!!
s_time=10;
w_time=4;
% offset_time=1;
open_system('velo');
open_system('velo/Scope');
set_param('velo','SimulationCommand','start');
while(1)
    stat = get_param('velo','SimulationStatus');
    if(strcmp(stat,'stopped'))
        break;
    end
    pause(3);
end
ScopeData = evalin('base','ScopeData');
y=ScopeData.signals.values;
t=ScopeData.time;
y_2=y(:,2);
c1=mean(y_2(w_time/ts:s_time/ts));
c2=mean(y_2((s_time+w_time)/ts:end));
figure();
plot(t,y,t,ones(size(t))*c1,'r--',t,ones(size(t))*c2,'r--');
xlabel('Time [s]');
ylabel('Velocity [V]');
k_id = (c2-c1)/p_const;
u_offset = (k_id*r_const-c1)/k_id;
y2=y_2(s_time/ts:end)-c1;
t2=t(s_time/ts:end);
t2=t2-t2(1);
tc_idx = min(find(y2 > (c2-c1)*0.632));
t_id = t2(tc_idx);
figure();
plot(t2,y2,'.',t_id,(c2-c1)*0.632,'ro',t2,ones(size(t2))*(c2-c1),'r--');
xlim([0 w_time]);
xlabel('Time [s]');
ylabel('Velocity [V]');
fprintf('==result==\n');
fprintf('Time step = %f\n',ts);
fprintf('K = %f\n',k_id);
fprintf('T = %f\n',t_id);
fprintf('u_offset = %f\n',u_offset);
end