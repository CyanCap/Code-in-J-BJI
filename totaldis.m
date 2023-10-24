function [output] = totaldis(pop)
global dis
[r,c]=size(pop);
output=zeros(r,1);
for i=1:r
    for j=1:c-1
        output(i)=output(i)+dis(pop(i,j),pop(i,j+1));
    end
    output(i)=output(i)+dis(pop(i,1),pop(i,c));
end
end

