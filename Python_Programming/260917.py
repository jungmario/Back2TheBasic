# 그냥 개인적인 궁금증 하나, 읽기단계에서 global namespace로 간다면, 함수안에서도 함수 밖 문자를 읽어올 수 있는가.
# a = 5  # Global 딕셔너리에 'a' 생성

# def my_func():
#     a = 10  # 🚨 Global의 'a'를 수정하는 게 아님!, 이거 지워서도 실행해봐, 함수안 print(a)의 a를 위에서 가져와서 할 수 있네ㅋㅋㅋㅋ
#             # Local 딕셔너리에 완전히 새로운 'a'라는 이름표를 하나 더 만듦!
#     print(a) # 10 출력 (Local)

# my_func()
# print(a) # 5 출력 (Global의 a는 아무 타격을 받지 않음)

# s = 'hello'
# print(s)
# s = list(s)
# print(s)
# s = str(s)
# print(s)

# l2 = [[1, 2, 3], [4, 8], [6], [4, 8]]
# print(str(l2))

# 1 ~ 100까지 홀수 인쇄
# print(*range(1,101,2))
# # 100 ~ 1까지 10배수로 인쇄
# print(*range(100,9,-10))



