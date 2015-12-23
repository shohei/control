%% psd_plot.m

mydata = [
6	3.269765
7	3.161251
8	2.860401
9	2.565210
10	2.340802
11	2.131994
12	1.972542
13	1.769717
14	1.631310
15	1.550665
16	1.422121
18	1.218025
20	1.124497
22	1.023128
24	0.886716
26	0.817967
28	0.710782
30	0.673470
32	0.592493
34	0.531564
36	0.492551
];
x = mydata(:,2); % Voltage  [V]
y = mydata(:,1); % Position [cm]

N = length(x);
A = [ x, y, ones(N,1) ];
Y = [ x.*y ];
% Least-squares solution
X = A\Y;

% Parameters
a  = X(1)*X(2)+X(3);
b = -X(2);
c =  X(1);
fprintf('a = %f\n',a)
fprintf('b = %f\n',b)
fprintf('c = %f\n',c)

% Fitting function
yfit = a./(x + b ) + c;

%% Plot figure
figure(1)
plot(x,y,'*',x,yfit);
xlabel('Voltage [V]')
ylabel('Distance [cm]')
legend('Measured','Calculated')
axis([0 3.5 0 40])

%% EOF of psd_plot.m