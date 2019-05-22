u1 = zeros(n,m);
u2 = zeros(n,m);
u3 = zeros(n,m);

g = length(line3)/60;

dbm3=zeros(60,3);
for j = 1:3
    e=1;
    for i = 1:60
        for k = e:int16(g*i)
            
            dbm3(i,j) = dbm3(i,j)+line3(k,j); 
        end
        
        dbm3(i,j) = dbm3(i,j)/(int16(g*i)-e+1);
        e = int16(g*i)+1;
        
        
        
% % %     old scale choice
%         k=int16(i*(235/60));
%         
%             dbm3(i,j) = (line3(k-1,j)+line3(k-1,j)+line3(k-2,j)+line3(k,j))/4 ;
%        end
    end
end

d3=100;
for i = 1:60
    u1(d3, i+7)=dbm3(i, 1);
    u2(d3, i+7)=dbm3(i, 2);
    u3(d3, i+7)=dbm3(i, 3);
              
end