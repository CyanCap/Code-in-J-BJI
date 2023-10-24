clear;clc;
% 定义城市坐标  
cities = [0.5,0.5; 0.3,0.4; 0.9,0.6; 0.7,0.8; 0.2,0.9];  
  
% 设置遗传算法参数  
pop_size = 50; % 种群规模  
num_gen = 100; % 迭代次数  
mutation_rate = 0.1; % 变异率  
  
% 初始化种群  
pop = init_pop(pop_size, cities);  
  
% 进化过程  
for i = 1:num_gen  
    % 计算适应度  
    fitness = calculate_fitness(pop, cities);  
      
    % 选择操作  
    parents = selection(pop, fitness);  
      
    % 交叉操作  
    offspring = crossover(parents);  
      
    % 变异操作  
    offspring = mutation(offspring, mutation_rate);  
      
    % 更新种群  
    pop = update_pop(pop, offspring);  
end  
  
% 计算最优路径和总距离  
[optimal_path, optimal_distance] = calculate_optimal(pop);  
disp(['最优路径：', num2str(optimal_path)]);  
disp(['总距离：', num2str(optimal_distance)]);  
  
% 初始化种群函数  
function pop = init_pop(pop_size, cities)  
    pop = zeros(pop_size, numel(cities));  
    for i = 1:pop_size  
        pop(i, :) = randperm(numel(cities));  
    end  
end  
  
% 计算适应度函数  
function fitness = calculate_fitness(pop, cities)  
    fitness = zeros(size(pop));  
    for i = 1:size(pop, 1)  
        path = pop(i, :);  
        distance = calculate_distance(path, cities);  
        fitness(i) = -distance; % 注意使用负值，因为遗传算法求最小值  
    end  
end  
  
% 选择操作函数  
function parents = selection(pop, fitness)  
    % 本例中使用轮盘赌选择法  
    total_fitness = sum(fitness);  
    p = fitness / total_fitness;  
    q = cumsum(p);  
    parents = zeros(size(pop));  
    for i = 1:size(pop, 1)  
        r = rand();  
        for j = 1:numel(q)  
            if r <= q(j)  
                parents(i, :) = pop(j, :);  
                break;  
            end  
        end  
    end  
end  
  
% 交叉操作函数  
function offspring = crossover(parents)  
    % 本例中使用部分映射交叉法（PMX）  
    num_pairs = floor(size(parents, 1) / 2);  
    offspring = zeros(size(parents));  
    for i = 1:num_pairs  
        parent1 = parents(i, :); parent2 = parents(i + num_pairs, :); % 取两个父代个体  
        alpha = rand(); beta = rand(); % 控制参数，需要进行调整和优化  
        g1 = sort([parent1(1), parent2(1)]); g2 = sort([parent1(end), parent2(end)]); % 选择交叉点位置  
        offspring1 = parent1; offspring2 = parent2; % 子代初始化  
        offspring1(beta*(1:numel(parent1)) + alpha*(g1+1):beta*(numel(parent1)+g2)+alpha) = parent2(g1+1:g2); % 子代1的交叉操作  
        offspring2(beta*(1:numel(parent2)) + alpha*(g1+1):beta*(numel(parent2)+g2)+alpha) = parent1(g1+1:g2); % 子代2的交叉操作  
        offspring((i-1)*2+1, :) = offspring1; offspring((i-1)*2+2, :) = offspring2; % 将两个子代加入到后代中  
    end
end
