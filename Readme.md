---------------------------------------------Operating system lab project-2022-----------------------------------------------
------------------------------------------------------Project : Deadlock simulation-----------------------------------------

ROHIT KUMAR
20cs3053

Language :C++

File:

1) Banker's_algorithm_implementation.c++
	                It contains all operations such as process creation,Deadlock simulation ,Alloc_resource file creation,
               Avail_resource file update,Max_resource file creation,need_resource file creation in notepad.

2) Alloc_resource.txt
		It is a 2-d array of size ‘n*m’ that defines the number of resources of each type currently allocated to each process.
		Allocation[ i, j ] = k means process Pi is currently allocated ‘k’ instances of resource type Rj

3) Avail_resource.txt
		It is a 1-d array of size ‘m’ indicating the number of available resources of each type.
		Available[ j ] = k means there are ‘k’ instances of resource type Rj

4)max_Need_resource.txt
		It is a 2-d array of size ‘n*m’ that defines the maximum demand of each process in a system.
		Max[ i, j ] = k means process Pi may request at most ‘k’ instances of resource type Rj.

5)need_resource.txt
		It is a 2-d array of size ‘n*m’ that indicates the remaining resource need of each process.
		Need [ i,   j ] = Max [ i,   j ] – Allocation [ i,   j ]

This code can be run in devc++,. Only main.c++ needs to be run.	
