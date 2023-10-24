function dis = discal(loc)
[x,y]=size(loc);
dis=zeros(70,70);

for i=1:x-1
    for j=i+1:x
        dis(i,j)=sqrt((loc(i,1)-loc(j,1))^2 + (loc(i,2)-loc(j,2))^2);
        dis(j,i)=dis(i,j);
    end
end

end

