
m = 76;
n = 120;
p = 86;
q = 16;
r = 65;

t = 1; 

x = 1:1:m;
y = 1:1:n;
[xx yy] = meshgrid(x, y);

j = 61;
s =1;

% -1-1-1-1-1-1-1-1-1-1-1-1---figure1_bmttvt-1-1-1-1-1-1-1-1-1-1-1-1

figure('name','RSSI of BMTTVT_FET ');
a = surf(z1);

for k = 1:length(a)
    zdata = a(k).ZData;
    a(k).CData = zdata;
    a(k).FaceColor = 'interp';
end

hold on;

b = surf(u1);

for k = 1:length(b)
    zdata = b(k).ZData;
    b(k).CData = zdata;
    b(k).FaceColor = 'interp';
end

c = surf(t1);

for k = 1:length(c)
    zdata = c(k).ZData;
    c(k).CData = zdata;
    c(k).FaceColor = 'interp';
end

shading interp

colorbar;
caxis([0 70]);
colormap(jet);
contourf(peaks);
colorbar('Ticks',[0,10,20,30,40,50,60,70],...
         'TickLabels',{'-100 dBm','-90 dBm','-80 dBm','-70 dBm','-60 dBm','-50 dBm','-40 dBm', '-30 dBm'})
     

axis equal;
 hold on;
img = imread('g2.PNG');
xlabel('x');
ylabel('y');
zlabel('z');
xImage = [0 m; 0 m];   
yImage = [0 0; n n];            
zImage = [0.5 0.5; 0.5 0.5 ];   


 for j = 1:90
     img(j, 40) = 15;
 end
 
 surf(xImage,yImage,zImage,...    
     'CData',img,...
     'FaceColor','texturemap');
 


 % 2-2-2-2-2-2-2-2-2-2-2--figure1_bmttvt-2-2-2-2-2-2-2-2-2-2
 
 
 figure('name','RSSI of Tenda_HTVT');
a = surf(z2);

for k = 1:length(a)
    zdata = a(k).ZData;
    a(k).CData = zdata;
    a(k).FaceColor = 'interp';
end

hold on;

b = surf(u2);

for k = 1:length(b)
    zdata = b(k).ZData;
    b(k).CData = zdata;
    b(k).FaceColor = 'interp';
end

c = surf(t2);

shading interp;

colorbar;
caxis([0 70]);
colormap(jet);
contourf(peaks);
colorbar('Ticks',[0,10,20,30,40,50,60,70],...
         'TickLabels',{'-100 dBm','-90 dBm','-80 dBm','-70 dBm','-60 dBm','-50 dBm','-40 dBm', '-30 dBm'})

for k = 1:length(c)
    zdata = c(k).ZData;
    c(k).CData = zdata;
    c(k).FaceColor = 'interp';
end
axis equal;
 hold on;
img = imread('g2.PNG');
xlabel('x');
ylabel('y');
zlabel('z');
xImage = [0 m; 0 m];   
yImage = [0 0; n n];            
zImage = [0.5 0.5; 0.5 0.5 ];   


 for j = 1:90
     img(j, 40) = 15;
 end
 
 surf(xImage,yImage,zImage,...    
     'CData',img,...
     'FaceColor','texturemap');


 % 3-3-3-3-3-3-3-3-3-3-3-3--figure1_bmttvt-3-3-3-3-3-3-3-3-3-3
 
 figure('name','RSSI of TP-LINK_5268_VPK');
a = surf(z3);

for k = 1:length(a)
    zdata = a(k).ZData;
    a(k).CData = zdata;
    a(k).FaceColor = 'interp';
end

hold on;

b = surf(u3);

for k = 1:length(b)
    zdata = b(k).ZData;
    b(k).CData = zdata;
    b(k).FaceColor = 'interp';
end

c = surf(t3);

for k = 1:length(c)
    zdata = c(k).ZData;
    c(k).CData = zdata;
    c(k).FaceColor = 'interp';
end

shading interp
colorbar;
caxis([0 70]);
colormap(jet);
contourf(peaks);
colorbar('Ticks',[0,10,20,30,40,50,60,70],...
         'TickLabels',{'-100 dBm','-90 dBm','-80 dBm','-70 dBm','-60 dBm','-50 dBm','-40 dBm', '-30 dBm'})
     

axis equal;
 hold on;
img = imread('g2.PNG');
xlabel('x');
ylabel('y');
zlabel('z');
xImage = [0 m; 0 m];   
yImage = [0 0; n n];            
zImage = [0.5 0.5; 0.5 0.5 ];   


 for j = 1:90
     img(j, 40) = 15;
 end
 
 surf(xImage,yImage,zImage,...    
     'CData',img,...
     'FaceColor','texturemap');
 

