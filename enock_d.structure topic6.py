class TreeNode:
    def __init__(self, name):
        self.name = name
        self.children = []

    def add_child(self, child):
        self.children.append(child)

    def display(self, level=0):
        print('  ' * level + self.name)
        for child in self.children:
            child.display(level + 1)

root = TreeNode('Marketplace')

category1 = TreeNode('Web Development')
category2 = TreeNode('Graphic Design')
category3 = TreeNode('Writing & Translation')
root.add_child(category1)
root.add_child(category2)
root.add_child(category3)

subcategory1 = TreeNode('Frontend Development')
subcategory2 = TreeNode('Backend Development')
category1.add_child(subcategory1)
category1.add_child(subcategory2)

freelancer1 = TreeNode('Alice - Frontend Developer')
freelancer2 = TreeNode('Bob - Frontend Developer')
subcategory1.add_child(freelancer1)
subcategory1.add_child(freelancer2)

freelancer3 = TreeNode('Charlie - Graphic Designer')
freelancer4 = TreeNode('Dave - Graphic Designer')
category2.add_child(freelancer3)
category2.add_child(freelancer4)

root.display()
