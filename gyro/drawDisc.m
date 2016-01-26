function [h1,h2,h3,h4,h5] = drawDisc(r,A)

% r = [1,1,1];       % Reference position
% A = [-pi/3, 0, 0]; % Reference orientation (x-y-z Euler angle)
xmax=3;
ymax=3;
zmax=3;
Radius = 1;
Height = 0.3;
SideCount = 20;
a1 = A(1);
a2 = A(2);
a3 = A(3);
R1 = [1, 0, 0;
    0, cos(a1), -sin(a1);
    0, sin(a1), cos(a1)];
R2 = [cos(a2), 0, sin(a2);
    0, 1, 0;
    -sin(a2), 0, cos(a2)];
R3 = [cos(a3), -sin(a3), 0;
    sin(a3), cos(a3), 0;
    0, 0, 1];
R = R1*R2*R3;
n_side = SideCount;

for i_ver=1:n_side
    VertexData_0(i_ver,:) = [Radius*cos(2*pi/n_side*i_ver),Radius*sin(2*pi/n_side*i_ver),0];
    VertexData_0(n_side+i_ver,:) = [Radius*cos(2*pi/n_side*i_ver),Radius*sin(2*pi/n_side*i_ver),Height];
end

n_ver = 2*n_side;

for i_ver=1:n_ver
    VertexData(i_ver,:) = r + VertexData_0(i_ver,:)*R';
end
for i_pat=1:n_side-1
    Index_Patch1(i_pat,:) = [i_pat,i_pat+1,i_pat+1+n_side,i_pat+n_side];
end
Index_Patch1(n_side,:) = [n_side,1,1+n_side,2*n_side];
for i_pat=1:n_side
    PatchData1_X(:,i_pat) = VertexData(Index_Patch1(i_pat,:),1);
    PatchData1_Y(:,i_pat) = VertexData(Index_Patch1(i_pat,:),2);
    PatchData1_Z(:,i_pat) = VertexData(Index_Patch1(i_pat,:),3);
end

PatchData3_X = VertexData(Index_Patch1(n_side,:),1);
PatchData3_Y = VertexData(Index_Patch1(n_side,:),2);
PatchData3_Z = VertexData(Index_Patch1(n_side,:),3);

figure(1);
h1 = patch(PatchData1_X,PatchData1_Y,PatchData1_Z,'y');
h3 = patch(PatchData3_X,PatchData3_Y,PatchData3_Z,'r');


Index_Patch2(1,:) = [1:n_side];
Index_Patch2(2,:) = [n_side+1:2*n_side];

for i_pat=1:2
    PatchData2_X(:,i_pat) = VertexData(Index_Patch2(i_pat,:),1);
    PatchData2_Y(:,i_pat) = VertexData(Index_Patch2(i_pat,:),2);
    PatchData2_Z(:,i_pat) = VertexData(Index_Patch2(i_pat,:),3);
end
h2 = patch(PatchData2_X,PatchData2_Y,PatchData2_Z,'y');
% set(gca,'FontSize',14);

h4=plot3([r(1) PatchData2_X(1,1)],[r(2) PatchData2_Y(1,1)],[PatchData2_Z(1,1) PatchData2_Z(1,1)],'r');
h5=plot3([r(1) PatchData2_X(1,1)],[r(2) PatchData2_Y(1,2)],[PatchData2_Z(1,2) PatchData2_Z(1,2)],'r');

axis vis3d equal;
% % view([-37.5,30]);
% camlight;
grid on;

xlim([-xmax xmax]);
ylim([-ymax ymax]);
zlim([-zmax zmax]);


end