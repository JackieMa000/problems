class SlidingWindow:

    def __init__(self, nums: list, k: int):
        self.nums = nums
        self.window_size = k

    def get_maxs_by_sliding(self) -> list:
        window, res = [], []
        for i, x in enumerate(self.nums):
            window = self.maintain_deque(i, window, x)
            self.append_max_num_from_window_to_results(i, res, window)
        return res

    def maintain_deque(self, i, window, element):
        window = self.make_window_leftout(i, window)
        window = self.make_window_rightout(window, element)
        window.append(i)
        return window

    def append_max_num_from_window_to_results(self, i, res, window):
        max_num = self.get_max_num(i, window)
        if max_num:
            res.append(max_num)

    def get_max_num(self, i, window):
        is_window = i >= self.window_size - 1
        return self.nums[window[0]] if is_window else None

    def make_window_leftout(self, i, window):
        is_leftout = i >= self.window_size and window[0] <= i - self.window_size
        if is_leftout:
            window.pop(0)
        return window

    def make_window_rightout(self, window, x):
        while window and self.nums[window[-1]] <= x:
            window.pop()
        return window
