# PSS : PUSH SWAP STACK

I implementent the stack as a double linked list that becomes circular. I do that cause this stack has to rotate. In  a conventional stack i has not acces to stack bottom in a fast way.
![imagen](https://github.com/luismiguelcasadodiaz/push_swap/blob/main/docs/media/stack.jpeg)

### Push element

![imagen](https://github.com/luismiguelcasadodiaz/push_swap/blob/main/docs/media/push.jpeg)

### Pop element

![imagen](https://github.com/luismiguelcasadodiaz/push_swap/blob/main/docs/media/pop.png)

### Swap two top element of the stack

![imagen](https://github.com/luismiguelcasadodiaz/push_swap/blob/main/docs/media/swap.jpeg)

### Rotate Stack, either forward or backward

![imagen](https://github.com/luismiguelcasadodiaz/push_swap/blob/main/docs/media/rotate.jpeg)


## testing
```bash
------- Testing allowed operations -------
pss(a){#:0, [0..0]}(empty)
pss(b){#:0, [0..0]}(empty)
pss(a){#:3, [1..3]}(1 2 3 )
pss(b){#:3, [4..6]}(4 5 6 )
sa
sb
pss(a){#:3, [1..3]}(2 1 3 )
pss(b){#:3, [4..6]}(5 4 6 )
sa
sb
pss(a){#:3, [1..3]}(1 2 3 )
pss(b){#:3, [4..6]}(4 5 6 )
ss
pss(a){#:3, [1..3]}(2 1 3 )
pss(b){#:3, [4..6]}(5 4 6 )
ss
pss(a){#:3, [1..3]}(1 2 3 )
pss(b){#:3, [4..6]}(4 5 6 )
ra
rb
pss(a){#:3, [1..3]}(2 3 1 )
pss(b){#:3, [4..6]}(5 6 4 )
rrr
pss(a){#:3, [1..3]}(1 2 3 )
pss(b){#:3, [4..6]}(4 5 6 )
rra
rrb
pss(a){#:3, [1..3]}(3 1 2 )
pss(b){#:3, [4..6]}(6 4 5 )
rr
pss(a){#:3, [1..3]}(1 2 3 )
pss(b){#:3, [4..6]}(4 5 6 )
pb
pss(a){#:2, [2..3]}(2 3 )
pss(b){#:4, [1..6]}(1 4 5 6 )
pa
pss(a){#:3, [1..3]}(1 2 3 )
pss(b){#:3, [4..6]}(4 5 6 )
```

