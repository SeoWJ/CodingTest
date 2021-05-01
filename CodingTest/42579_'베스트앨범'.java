import java.util.*;

class Song implements Comparable<Song>{
    int songNumber;
    int songPlayedCount;

    Song(int songNumber, int songPlayedCount){
        this.songNumber = songNumber;
        this.songPlayedCount = songPlayedCount;
    }

    @Override
    public int compareTo(Song o){
        if(o.songPlayedCount != this.songPlayedCount)
            return o.songPlayedCount - this.songPlayedCount;
        else
            return this.songNumber - o.songNumber;
    }
}

class Genre implements Comparable<Genre>{
    String genreName;
    int playedCount;

    Genre(String genreName, int playedCount){
        this.genreName = genreName;
        this.playedCount = playedCount;
    }

    @Override
    public int compareTo(Genre o){
        return o.playedCount - this.playedCount;
    }
}

class Solution42579 {
    public int[] solution(String[] genres, int[] plays) {
        int[] answer = {};

        HashMap<String, Integer> playCount = new HashMap<>();
        HashMap<String, PriorityQueue<Song>> priorityQueueHashMap = new HashMap<>();
        List<Integer> answerList = new ArrayList<>();

        for(int i=0; i<genres.length; i++) {
            if (!playCount.containsKey(genres[i]))
                playCount.put(genres[i], plays[i]);
            else
                playCount.replace(genres[i], playCount.get(genres[i]) + plays[i]);

            if (!priorityQueueHashMap.containsKey(genres[i]))
                priorityQueueHashMap.put(genres[i], new PriorityQueue<>());
            priorityQueueHashMap.get(genres[i]).add(new Song(i, plays[i]));
        }

        PriorityQueue<Genre> genrePriorityQueue = new PriorityQueue<>();

        Iterator<String> keys = playCount.keySet().iterator();
        while(keys.hasNext()){
            String key = keys.next();
            genrePriorityQueue.add(new Genre(key, playCount.get(key)));
        }

        while(!genrePriorityQueue.isEmpty()){
            String genre = genrePriorityQueue.peek().genreName;
            int playedCount = genrePriorityQueue.peek().playedCount;

            genrePriorityQueue.poll();

            answerList.add(priorityQueueHashMap.get(genre).poll().songNumber);
            if(!priorityQueueHashMap.get(genre).isEmpty())
                answerList.add(priorityQueueHashMap.get(genre).poll().songNumber);
        }

        answer = new int[answerList.size()];
        for(int i=0; i<answer.length; i++)
            answer[i] = answerList.get(i);

        return answer;
    }
}