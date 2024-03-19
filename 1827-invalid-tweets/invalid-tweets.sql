-- Write your PostgreSQL query statement below
select tweet_id from Tweets
where LENGTH(content) > 15