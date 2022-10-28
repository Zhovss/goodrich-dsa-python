'''
Job Sequencing Problem with Deadlines
Given a list of tasks with deadlines and total profit earned on completing a task, 
find the maximum profit earned by executing the tasks within the specified deadlines. 
Assume that each task takes one unit of time to complete, and a task can't execute
beyond its deadline. Also, only a single task will be executed at a time.
'''

'''
Ý tưởng: 
B1: Tạo ra 1 class Job chứa các thông tin của job bao gồm task_id, deadline và profit của job
B2: Sắp xếp các job theo thứ tự giảm dần của profit
B3: Tạo ra 1 list slot để track xem công việc đã được sắp xếp hay chưa
B4: Sử dụng vòng lặp for, đầu tiên duyệt qua toàn bộ các job theo thứ tự đã sắp xếp, sau đó
    duyệt thêm 1 vòng for nữa nhằm xác định xem trong khoảng thời gian từ deadline của job đó
    về 1 có slot nào trống không, nếu có thì add vào, nếu không thì bỏ qua vì thứ tự đã được sắp
    xếp theo profit, có bỏ qua cũng không sao.
'''


class Job:
    def __init__(self, task_id, deadline, profit):
        self.task_id = task_id
        self.deadline = deadline
        self.profit = profit


def schedule_jobs(jobs: list[int]) -> None:
    # tracking profit thu được từ việc sắp xếp
    profit = 0
    
    slot = [-1] * len(jobs)
    
    # Sắp xếp theo thứ tự giảm dần của profit
    jobs.sort(key=lambda x: x.profit, reverse=True)
    
    for job in jobs:
        # kiểm tra xem slot có đang trống không và các ô trống
        # có thoả mãn deadline hay không
        for j in reversed(range(job.deadline)):
            if slot[j] == -1:
                slot[j] = job.task_id
                profit += job.profit
                break
    
    print("Thứ tự công việc đã sắp xếp: {}".format(list(filter(lambda x: x != -1, slot))))
    print("Total profit: {}".format(profit))
    

def main():
    jobs = [
        Job(1, 9, 15), Job(2, 2, 2), Job(3, 5, 18), Job(4, 7, 1), Job(5, 4, 25),
        Job(6, 2, 20), Job(7, 5, 8), Job(8, 7, 10), Job(9, 4, 12), Job(10, 3, 5)
    ]
    schedule_jobs(jobs)
    

if __name__ == "__main__":
    main()