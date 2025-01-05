from collections import deque

MAX_ORDERS = 5

order_queue = deque(maxlen=MAX_ORDERS)

order_queue.append('Order 1')
order_queue.append('Order 2')
order_queue.append('Order 3')
order_queue.append('Order 4')
order_queue.append('Order 5')
order_queue.append('Order 6')  
order_queue.append('Order 7')  

while order_queue:
    order = order_queue.popleft()
    print(f'Processing {order}')
