with dfs we can always check on each call if we can connect to our starting node.

let $N(v)$ denote the set of adjacent nodes of $v$

the idea is to use dfs but with the following modification:

each time we select a node, we update the current path we have taken from our root node $v'$ then anytime an already visited node is in the selection, this means that we have a cycle, because we already visited that node.

$path = (v)$ is the path we extend it with $path \cup w=(v,w)$
we check if a node is in the path with $z\in path$ 
# task 2
$||$ analogous to sets measures the length of the path

$findc(v,path)$

$\;\forall w \in N(v)\, do$

$\;if w\in path$

$\;return\;true$

after the loop

$results = \empty$

$\forall w \in N(v)$

$\;\; results = \cup findc(w,path\cup w$)

$\;\; if\, true\in results\, return\, true$

$\;return\,false$

in the first line we check if the current node was already visited and if we have more or two nodes in the path

if not we continue with dfs and update path before we make the next call.

otherweise if the neighbourhood is empty return false.

# task 3

two paths from $a$ to $b$ are different if they have at least one different edge 

we run the dfs algorithm from our starting node then each time we reach our target node, we increment the counter by one.

# task 4

for all neighbours of node 1 be delete them and reconnect all edges that were previously connected to some neighbour of  a, to a , the new graph now has all 2-hop neighbours as direct neighbours of a

for instance:

$(a,b),(b,c),(a,d),(d,b),(d,z)$

if we merge the neighbourhood of a we get the graph

$(a,c),(a,z)$ this direct neighbourhood of $a$ are all previously 2-hop neighbours


so for the last subtask an naiive approach would be to repeat this operation k-1 times for every node.

