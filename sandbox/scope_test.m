close all;
clear all;

simset('SrcWorkspace','current');


open_system('hoge');
open_system('hoge/Scope');

ts=1/10;
set_param('hoge','SimulationCommand','start');
while(1)
   stat=get_param('hoge','SimulationStatus');
    if strcmp(stat,'stopped')
      break; 
   end
   pause(5);
end
t=ScopeData.time;
length(t)

ts=1/50;
set_param('hoge','SimulationCommand','start');
while(1)
   stat=get_param('hoge','SimulationStatus');
    if strcmp(stat,'stopped')
      break; 
   end
   pause(5);
end
t=ScopeData.time;
length(t)


ts=1/100;
set_param('hoge','SimulationCommand','start');
while(1)
   stat=get_param('hoge','SimulationStatus');
    if strcmp(stat,'stopped')
      break; 
   end
   pause(5);
end
t=ScopeData.time;
length(t)


ts=1/1000;
set_param('hoge','SimulationCommand','start');
while(1)
   stat=get_param('hoge','SimulationStatus');
    if strcmp(stat,'stopped')
      break; 
   end
   pause(5);
end
t=ScopeData.time;
length(t)

