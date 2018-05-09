if __name__ == "__main__":
    q = int(input())
    for i in range(0,q):
        line = [int(i) for i in input().split(' ')]
        jobs = [int(i) for i in input().split(' ')]

        my = line[1]
        found = False
        time = 0

        while not found:
            time = time + 1
            max = 0
            index = 0
            i = 0

            for job in jobs:
                if max < job:
                    index = i
                    max = job
                i = i + 1
            jobs = jobs[index + 1:len(jobs)] + jobs[0:index]
            if index == my:
                found = True
            elif index > my:
                my = (my - index) % len(jobs)
            else: 
                my = my - index - 1
            
        print(time)
            