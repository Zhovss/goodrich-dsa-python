'''Find the duplicate element in a limited range array.
Given a limited range array of size n containing elements between 1 and n-1 with one element repeating,
find the duplicate number in it without using any extra space.'''

'''Theo đáp án, có thể dùng 4 cách để giải, các phương pháp đó phù hợp với các cấu trúc dữ liệu của cả 
3 ngôn ngữ, trong đó 3/4 phương pháp chỉ có thể sử dụng cho data dạng số (int, float,...). Phương pháp longmeow
sử dụng có thể dùng cho tất cả các datatypes và chỉ chạy được trên python do sử dụng một cấu trúc dữ liệu của python
là set - là một container chứa data với 3 tiêu chí: unordered, unchangeable, unindexed, đi kèm với đặc tính 
"Duplicates Not Allowed", sử dụng hash để loại trừ những thành phần trùng nhau ở trong set'''

'''Ý tưởng: Tạo một set rỗng rồi kiểm tra xem từng phần tử của list có ở trong set không, nếu không có thì add vào trong set,
nếu có rồi thì append vào dup_list, do tính chất của set chỉ nhận các obj trùng nhau một lần duy nhất, ngoài ra có thể cải tiến
thêm là xác định các phần tử bị trùng "unique", kể cả khi nó lặp lại nhiều lần là thay thế dup_list bằng dup_set'''


import sys


def find_dup(data: list[int]) -> int:
    temp_set = set()
    dup_list = []
    for element in data:
        if element not in temp_set:
            temp_set.add(element)
        else:
            dup_list.append(element)
    
    return dup_list


def main():
    dup = find_dup(list(map(int, sys.argv[1:])))
    print("The duplicate number is: {}".format(dup))        


if __name__ == "__main__":
    main()