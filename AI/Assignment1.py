import sys
from Node import Node



def main():
	
	file_name = sys.argv[1]
	o_city = sys.argv[2]
	g_city = sys.argv[3]


	f=open(file_name,'r')

	data = [line for line in f]

	f.close()

	graph = []

	for route in data:
		graph.append(route.lower().split())

	del graph[len(graph)-1]
	del graph[len(graph)-1]

	origin = Node(o_city, None, 0, 0)
	bfs(graph, origin, g_city)

def bfs(graph, origin, g_city):

	explored = [] # List of all explored cities
	queue = [origin]

	while queue: 

		if queue[0] == g_city:
			return queue[0]

		queue = find_adjacent_nodes(graph, queue, explored, g_city)
	

	print(queue)




def find_adjacent_nodes(graph, queue, explored, g_city):
	node = queue[0]
	name = node.city_name
	cost = node.total_cost

	explored.append(name)

	del queue[0]

		for route in graph:
			if name in route:

				if name == route[0]  and not(route[1] in explored):
					queue.append(Node(route[1], route[0], int(cost)+int(route[2]), int(route[2])))
				elif name == route[1] and not(route[0] in explored):
					queue.append(Node(route[0]), route[1], int(cost)+int(route[2], int(route[2])))

		return queue













main()
	


