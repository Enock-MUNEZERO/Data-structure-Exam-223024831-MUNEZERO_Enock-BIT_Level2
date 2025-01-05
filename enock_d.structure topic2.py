#Let's implement a Binary Search Tree (BST) and Singly Linked List in Python to manage data in an online marketplace for freelancers. 
# I'll provide the code for both data structures, and then explain how they can be used together.
# #Binary Search Tree (BST) Implementation:

class TreeNode:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.left = None
        self.right = None

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, key, value):
        if self.root is None:
            self.root = TreeNode(key, value)
        else:
            self._insert(self.root, key, value)

    def _insert(self, node, key, value):
        if key < node.key:
            if node.left is None:
                node.left = TreeNode(key, value)
            else:
                self._insert(node.left, key, value)
        elif key > node.key:
            if node.right is None:
                node.right = TreeNode(key, value)
            else:
                self._insert(node.right, key, value)
        else:
            node.value = value  # Update value if key already exists

    def search(self, key):
        return self._search(self.root, key)

    def _search(self, node, key):
        if node is None or node.key == key:
            return node
        if key < node.key:
            return self._search(node.left, key)
        return self._search(node.right, key)

    def delete(self, key):
        self.root = self._delete(self.root, key)

    def _delete(self, node, key):
        if node is None:
            return node

        if key < node.key:
            node.left = self._delete(node.left, key)
        elif key > node.key:
            node.right = self._delete(node.right, key)
        else:
            if node.left is None:
                return node.right
            elif node.right is None:
                return node.left

            temp = self._minValueNode(node.right)
            node.key = temp.key
            node.value = temp.value
            node.right = self._delete(node.right, temp.key)
        
        return node

    def _minValueNode(self, node):
        current = node
        while current.left is not None:
            current = current.left
        return current

# Example:
bst = BinarySearchTree()
bst.insert(10, "Freelancer A")
bst.insert(20, "Freelancer B")
bst.insert(5, "Freelancer C")

result = bst.search(10)
if result:
    print("Found:", result.value)
else:
    print("Not Found")






#Singly Linked List Implementation:
class ListNode:
    def __init__(self, value):
        self.value = value
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None

    def insert(self, value):
        new_node = ListNode(value)
        new_node.next = self.head
        self.head = new_node

    def delete(self, value):
        current = self.head
        prev = None
        while current is not None:
            if current.value == value:
                if prev is None:
                    self.head = current.next
                else:
                    prev.next = current.next
                return
            prev = current
            current = current.next

    def search(self, value):
        current = self.head
        while current is not None:
            if current.value == value:
                return current
            current = current.next
        return None

# Example:
sll = SinglyLinkedList()
sll.insert("Freelancer X")
sll.insert("Freelancer Y")
sll.insert("Freelancer Z")

result = sll.search("Freelancer Y")
if result:
    print("Found:", result.value)
else:
    print("Not Found")



#Example Integration:
class Freelancer:
    def __init__(self, id, name):
        self.id = id
        self.name = name
        self.projects = SinglyLinkedList()

# Initialize BST for storing freelancers
freelancers_bst = BinarySearchTree()

# Adding freelancers
freelancers_bst.insert(1, Freelancer(1, "Freelancer A"))
freelancers_bst.insert(2, Freelancer(2, "Freelancer B"))

# Searching for a freelancer and adding projects
freelancer_node = freelancers_bst.search(1)
if freelancer_node:
    freelancer = freelancer_node.value
    freelancer.projects.insert("Project 1")
    freelancer.projects.insert("Project 2")

# Listing all projects of a freelancer
project_node = freelancer.projects.head
while project_node:
    print("Project:", project_node.value)
    project_node = project_node.next
