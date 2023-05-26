with dfs we can always check on each call if we can connect to our starting node.

let $N(v)$ denote the set of adjacent nodes of $v$

the idea is to use dfs but with the following modification:

each time we select a node, we update the current path we have taken from our root node $v'$ then anytime an already visited node is in the selection, this means that we have a cycle, because we already visited that node.

$path = (v)$ is the path we extend it with $path \cup w=(v,w)$
we check if a node is in the path with $z\in path$ 

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

