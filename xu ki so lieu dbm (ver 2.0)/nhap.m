m = 73;
n = 120;
p = 86;
q = 16;
r = 65;

t = 1; 

x = 1:1:m;
y = 1:1:n;
[xx yy] = meshgrid(x, y);

surf(u1);






% for i = 5:55
%     z(86, i)=15;
%               
% end
% k=85
% while k >= 18
%     s=s+1;
%     z(k, 14)= dbm(s);
%     z(k, 15)= dbm(s);
%     z(k, 16)= dbm(s);
%     z(k, 17)= dbm(s);
%     k = k-1;
% end
% for i = 18:86
%     z(i, 16)=15;
%     
% end
% 
% for i = 5:55
%     s=s+1;
%     z(15, i)=dbm(s);
%     z(16, i)=dbm(s);
%     z(17, i)=dbm(s);
%     z(18, i)=dbm(s);
%     z(19, i)=dbm(s);
%     
% end
% 
% 
% figure('name','RSSI of BMTTVT_FET ');
% 
% 
% 
% 
% b = surf(z1);
% grid off;
% 
% for k = 1:length(b)
%     zdata = b(k).ZData;
%     b(k).CData = zdata;
%     b(k).FaceColor = 'interp';
% end
% 
% axis equal;
%  hold on;
% img = imread('g2.PNG');
% xlabel('x');
% ylabel('y');
% zlabel('z');
% xImage = [0 m; 0 m];   
% yImage = [0 0; n n];            
% zImage = [0.5 0.5; 0.5 0.5 ];   
% 
% 
%  for j = 1:90
%      img(j, 40) = 15;
%  end
%  
%  surf(xImage,yImage,zImage,...    
%      'CData',img,...
%      'FaceColor','texturemap');
%  
%  figure('name','RSSI of Tenda_HTVT');
%  j = 61;
% s=0;
% 
%  while j >= 5
%     s=s+1;
%     
%     z2(17, j+3)= dbm2(s);
%     z(87, j+3)= dbm(s);
%     
%     j = j-1;
% end
% 
% for i = 5:55
%     z(86, i)=15;
%               
% end
% k=85
% while k >= 18
%     s=s+1;
%     z(k, 14)= dbm(s);
%     z(k, 15)= dbm(s);
%     z(k, 16)= dbm(s);
%     z(k, 17)= dbm(s);
%     k = k-1;
% end
% for i = 18:86
%     z(i, 16)=15;
%     
% end
% 
% for i = 5:55
%     s=s+1;
%     z(15, i)=dbm(s);
%     z(16, i)=dbm(s);
%     z(17, i)=dbm(s);
%     z(18, i)=dbm(s);
%     z(19, i)=dbm(s);
%     
% end
% 
% b = surf(z2);
% grid off;
% 
% for k = 1:length(b)
%     zdata = b(k).ZData;
%     b(k).CData = zdata;
%     b(k).FaceColor = 'interp';
% end
% 
% axis equal;
%  hold on;
% img = imread('g2.PNG');
% xlabel('x');
% ylabel('y');
% zlabel('z');
% xImage = [0 m; 0 m];   
% yImage = [0 0; n n];            
% zImage = [0.5 0.5; 0.5 0.5 ];   
% 
% 
%  for j = 1:90
%      img(j, 40) = 15;
%  end
%  
%  surf(xImage,yImage,zImage,...    
%      'CData',img,...
%      'FaceColor','texturemap');
%   
%  figure('name','RSSI of TP-LINK_5268_VPK');
%  s=0;
%  j = 61;
%  while j >= 1
%     s=s+1;
%     
%     z(17, j+10)= dbm3(s);
%     z(87, j+10)= dbm(s);
%     
%     j = j-1;
% end
% 
% for i = 5:55
%     z(86, i)=15;
%               
% end
% k=85;
% while k >= 18
%     s=s+1;
%     z(k, 14)= dbm(s);
%     z(k, 15)= dbm(s);
%     z(k, 16)= dbm(s);
%     z(k, 17)= dbm(s);
%     k = k-1;
% end
% for i = 18:86
%     z(i, 16)=15;
%     
% end
% 
% for i = 5:55
%     s=s+1;
%     z(15, i)=dbm(s);
%     z(16, i)=dbm(s);
%     z(17, i)=dbm(s);
%     z(18, i)=dbm(s);
%     z(19, i)=dbm(s);
%     
% end
% 
% b = surf(z);
% grid off;
% 
% for k = 1:length(b)
%     zdata = b(k).ZData;
%     b(k).CData = zdata;
%     b(k).FaceColor = 'interp';
% end
% 
% axis equal;
%  hold on;
% img = imread('g2.PNG');
% xlabel('x');
% ylabel('y');
% zlabel('z');
% xImage = [0 m; 0 m];   
% yImage = [0 0; n n];            
% zImage = [0.5 0.5; 0.5 0.5 ];   
% 
% 
%  for j = 1:90
%      img(j, 40) = 15;
%  end
%  
%  surf(xImage,yImage,zImage,...    
%      'CData',img,...
%      'FaceColor','texturemap');
% 



