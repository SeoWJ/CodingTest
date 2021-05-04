class Solution72410 {
    public String step1(String id){
        String new_id = id.toLowerCase();
        return new_id;
    }

    public String step2(String id){
        String new_id = "";

        for(int i=0; i<id.length(); i++){
            if(('a' <= id.charAt(i) && id.charAt(i) <= 'z') || ('0' <= id.charAt(i) && id.charAt(i) <= '9') || id.charAt(i) == '-' || id.charAt(i) == '_' || id.charAt(i) == '.')
                new_id += id.charAt(i);
        }

        return new_id;
    }

    public String step3(String id){
        String new_id = id.substring(0, 1);

        for(int i=1; i<id.length(); i++){
            if(new_id.charAt(new_id.length() - 1) == '.' && id.charAt(i) == '.')
                continue;
            else
                new_id += id.charAt(i);
        }

        return new_id;
    }

    public String step4(String id){
        String new_id = "";

        for(int i=0; i<id.length(); i++){
            if((i==0 || i==id.length() - 1) && id.charAt(i) == '.')
                continue;
            else
                new_id += id.charAt(i);
        }

        return new_id;
    }

    public String step5(String id){
        if(id.isEmpty())
            return "a";
        else
            return id;
    }

    public String step6(String id){
        if(id.length() >= 16) {
            id = id.substring(0, 15);

            if(id.charAt(14) == '.')
                id = id.substring(0, 14);
        }

        return id;
    }

    public String step7(String id){
        if(id.length() <= 2){
            while(id.length() < 3)
                id += id.charAt(id.length() - 1);
        }

        return id;
    }

    public String solution(String new_id) {
        String answer = "";

        answer = step1(new_id);
        answer = step2(answer);
        answer = step3(answer);
        answer = step4(answer);
        answer = step5(answer);
        answer = step6(answer);
        answer = step7(answer);

        return answer;
    }
}

class Main72140{
    public static void main(String[] args){
        Solution72410 s = new Solution72410();
        s.solution("z-+.^.");
    }
}