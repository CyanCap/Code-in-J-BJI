% clear;clc;

location=csvread("st70.csv");
dis=discal(location);          
[x,y]=size(location);

nk=100;   % quantity of ants
rho=0.2;    % factor of pheromones evaporate
a=2;    % alpha
b=5;    % beta
Q=100;   % power of pheromones
its=20;    % number of iterations
its_c=1;    % count the iterations

eta = 1./dis; % ¦Ç
T = ones(x,x);    % ¦Ó matrix
path = zeros(nk,x); % path of each ant
path_best = zeros(its,x);   % best path of each iteration
l = zeros(nk,1);  % distance of each ant walked
l_best = inf.*ones(its,1);  % best distance of each iteration
T_delta = zeros(x,x);   % sum of ¦¤¦Ó^k

while its_c <= its
    
    temp=randi(x,nk,1);
    path(:,1)=temp(1);  % place all ants to random cities
    
    path = path_construct(path,a,b,eta,nk,T,location);   
    
    l=distance_information(path,dis);
    [path_best,l_best]=reserve(path,l,path_best,l_best,its_c);
    path(1,:)=path_best(its_c,:);   % reserve the best path so far
    
    T = phe_update(path,l,rho,Q,nk,T,T_delta,location);
     
%     drawnow;                        % visualization
%     hold off;
%     plot(1:its,l_best);
%     title(['its=',num2str(its_c),'  distance=',num2str(l_best(its_c))]);
%     xlabel('Iterations');ylabel('Distance of best tourment');
%     legend('best distance')
    
    path = zeros(nk,x);
    its_c=its_c+1;
end
% l_best(end)

function dis = discal(loc)   % calculate the distance matrix
[r,l]=size(loc);
dis=zeros(70,70);
for i=1:r-1
    for j=i+1:r
        dis(i,j)=sqrt((loc(i,1)-loc(j,1))^2 + (loc(i,2)-loc(j,2))^2);
        dis(j,i)=dis(i,j);
    end
end
end
function [path] = path_construct(path,a,b,eta,nk,T,location) % construct path for each ant
[x,~] = size(location);
for i=2:x       % process the path according the probabilities
    for j=1:nk
        visited = path(j,1:(i-1));
        nvisited = zeros(1,(x-i+1));    % not visited
        p = nvisited;   % probability of not visited
        vnum=1; % number of visited cities
        for k=1:x
            if isempty(find(visited==k,1))
                nvisited(vnum) = k;
                vnum = vnum + 1;
            end
        end
        for q=1:(x-i+1)
            p(q) = ( T(visited(end), nvisited(q))^a ) * (eta(visited(end), nvisited(q))^b );    % calculate numerator of probability
        end
        p = p./(sum(p));    % transition probility
        
        pc = cumsum(p);
        choice = find(pc>=rand);    % roulette
        path(j,i) = nvisited( choice(1) );  % construct next node to path
    end
end
end
function [l]=distance_information(path,dis)     % calculate distance for each ants
[r,c]=size(path);
l=zeros(r,1);
for i=1:r
    for j=1:c-1
        l(i)=l(i)+dis(path(i,j),path(i,j+1));
    end
    l(i)=l(i)+dis(path(i,1),path(i,c));
end
end
function [path_best, l_best]=reserve(path,l,path_best,l_best,its_c)     % find the best path
if its_c>=2
    if min(l)<=l_best(its_c-1)
        l_best(its_c)=min(l);               % find best distance
%         temp=l==l_best(its_c);
        temp=find(l==l_best(its_c),1);
        path_best(its_c,:)=path(temp,:);    % find best path
    else
        l_best(its_c)=l_best(its_c-1);
        path_best(its_c,:)=path_best(its_c-1,:);
    end
else
    l_best(its_c)=min(l);
    temp=find(l==l_best(its_c),1);
    path_best(its_c,:)=path(temp,:)';
end
end
function [T] = phe_update(path,l,rho,Q,nk,T,T_delta,location)   % update the pheromone
[x,~]=size(location);
for i=1:nk
    for j=1:(x-1)
       T_delta(path(i,j),path(i,j+1))=T_delta(path(i,j),path(i,j+1)) + Q./l(i); 
    end
    T_delta(path(i,x),path(i,1))=T_delta(path(i,x),path(i,1)) + Q./l(i);
end
T=(1-rho).*T+T_delta;
end


