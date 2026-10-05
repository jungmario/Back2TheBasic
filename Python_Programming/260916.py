# #1 : 4자리수 n의 각 자리값을 저장.
# n = 1234
# d1 = n // 1000 
# d2 = (n // 100) % 10 # 이렇게 하는 게 좀 어렵네
# d3 = (n // 10) % 10
# d4 = n % 10
# print( d1, d2, d3, d4 )


# #2 : 디렉토리 형식 문자열 인쇄
# print( 'C:\\temp' ) # \t땜에 뛰니까 \하나 더 붙여서 그냥 일반문자로 취급. or 앞에 r을 붙이든가.

# #3 : 문자열 정수 연산
# a, b = '10', '20'
# r = int(a) + int(b)
# print(r)

# #3 : 제품 판매가격 계산
# p, t = '123456', '12.5'

# total = int(p) + int(p) * float(t) / 100
# total = (total // 1000) * 1000 # 1000원 미만 절사하기.
# print(int(total))

# #4 : 두 정수 입력 받아 합 구하기
# a = int(input())
# b = int(input())

# print( a + b )

# #5 : split()을 이용한 이름 3개 입력 받기
# a, b, c = input().split()
# a, b, c = int(a), int(b), int(c)



#  # 또는 a, b, c = int(a), int(b), int(c)

# print(a + b + c)
