# s1 = [1, 2]
# s2 = [3, 4]

# s3 = s1 + s2

# s1[0] = 2

# print(s3)


# v = (10, 4, 2, -10)
# e = (2, 3, 4, 2)

# print(*map(pow, v, e))

# print(list(map(int, input().split)))


# def string_repeat(s, n) :
#     x = s * n



#     return x

# s, n = input().split()
# n = int(n)

# x = string_repeat(s,n)
# print(x, sep =' ')

# cnt = 0

# def func() :
#     cnt += 1 # cnt = cnt + 1 : 우변 cnt는 쓰기 작업이므로 읽어오는 공간은 local name space로 한정. 거기에 cnt가 바인딩 안된채로 있음 -> 에러.

# func()
# func()

# print(cnt)


# l = list(map(float, input().split()))

# def round_square(x) :

#     return round(x) ** 2 # 엄밀히 말하면 ()가 붙은채로 나오는거네

# print(*map(round_square, l))


# data = [
#     ('modelA', 'factoryB'), 
#     ('modelB', 'factoryC'),
#     ('modelA', 'factoryA')
# ]

# print(*data, sep = '\n')
# print('----------------------------------')

# # 1단계: 2순위 조건(제조공장)으로 먼저 '내림차순' 정렬을 해버립니다.
# step1 = sorted(data, key=lambda x: x[1], reverse=True)

# print(*step1, sep = '\n')
# print('----------------------------------')

# # 2단계: 1단계의 결과물을 가지고 1순위 조건(모델명)으로 '오름차순' 정렬을 합니다.
# final_result = sorted(step1, key=lambda x: x[0])

# print(*final_result, sep = '\n') # 이러면 되네 우선순위 낮은거부터 sorted해서 결국 마지막에 우선순위 높은거 sorted하면....

# a, b = 20, 10
# print(a if a > b else b)


# sen = input().split()
# print( *(('*' + x[1::]) for x in sen if x[0] == 'a')) # a가 아니라 'a'여야 하네...



# m = ((11, 2, 33, 4), (5, 6), (90, 10, 11, 12))
# r = tuple(y for x in m for y in x)
# l = []
# print(type(l) == list)

# g = (f'{i} * {j} = {i * j}' for i in range(2,10) for j in range(1,10))

# print(*g, sep = '\n')

# n = int(input())
# num = [int(x) for x in input().split()]

# print(*[x for x in num if x >= 10])

# print(input().split())

# str = 'abcd'
# print(id(a[0]),id('a'), sep = '\n')

# print(str[0] == 'a')

# print(str[0] is 'a')

# print(type(input))


# t = ('kim', 'lee', 'park', 'kim', 'song', 'lee')

# s = input()

# for i in range(len(t)):
#     if t[i] == s : print(i)

# t = ((1, 2, 3, 4), (5, 6, 7, 8), (9, 10, 11, 12))

# # t = list(zip(*t))
# # print( *(y for x in t for y in x))

# # for i in range(4):
# #     for j in range(3):
# #         print(t[j][i], end = ' ')

# print((1, 2, 3, 4) in t)

print(max('14', '12'))