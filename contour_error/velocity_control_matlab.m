clear all; close all;
slkname = 'velocity_control';
macro_txt={'Kvp=1;m=1;','Kvp=2;m=1;','Kvp=4;m=1;'};
tmax=4;t=0:0.05:tmax;
w=logspace(-1,1);,
Linespec = {'-k','--r',':b'};

for ii=1:length(macro_txt)
   eval(macro_txt{ii});
   [A B C D] = linmod(slkname);
   sys=ss(A,B,C,D);
   
   y=step(sys,t);
   [mg ph] = bode(sys,w);
   mg = permute(mg,[3 1 2]);
   ph = permute(ph,[3 1 2]);
   
   figure(1); 
   plot(t,y(:,1,1),Linespec{ii});
   hold on;
   title('(a) time response');
   xlabel('t s');
   ylabel('response');
   axis([0 tmax 0 1.2]);
   figure(2);
   semilogx(w,20*log10(mg(:,1,1)),Linespec{ii});
   hold on;
   title('(b) frequency response');
   xlabel('\omega rad/s');
   ylabel('gain db');
   axis([0.1 10 -20 5]);
        
end












