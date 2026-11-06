# Heaps

## Kth smallest element in an array

I'll use a max-heap of size k. I push elements and if the heap gets too big, I pop the largest, which ensures only the k smallest elements remain, with the kth smallest at the top.

- It's easy to confuse max-heap for Kth smallest vs. min-heap for Kth largest; remember which one to use.
- TC O(N log K), SC O(K)

## Design Twitter

Merge everyone's tweet timelines using a max-heap to get the 10 most recent tweets. Don't forget user's own tweets.

- Remember to include the current user's own tweets in their news feed.
- TC postTweet: O(1), follow/unfollow: O(logF), getNewsFeed: O(K logF) where F is num followed users, K=10, SC O(U + T + F) where U is total users, T is total tweets, F is max followees for one user
