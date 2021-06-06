import domain

domain_1 = domain.Domain()
domain_2 = domain.Domain()
assert domain_1 != domain_2

node_1 = domain.Node(0, 1, 0.0, 0.0)
node_2 = domain.Node(0, 1, 0.0, 0.0)

assert node_1 != node_2

domain_1.addNode(node_1)
domain_2.addNode(node_2)

assert domain_1.getNode(0) != domain_2.getNode(0)
print("Success")


del domain_1
del domain_2
print("Success - domains deleted")

del node_1
print("Success - node 1 deleted")
del node_2
print("Success - nodes deleted")

a = None


