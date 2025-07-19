import java.util.Arrays;
class Solution {
    public List<String> removeSubfolders(String[] folder) {
        Arrays.sort(folder);
        int i = 1;
        String cur = folder[0];
        List<String> res = new ArrayList<>();
        res.add(cur);
        while(i < folder.length) {
            while(i < folder.length && (folder[i].startsWith(cur) && folder[i].charAt(cur.length()) == '/')) i++;
            if(i < folder.length) {
                cur = folder[i];
                res.add(cur);
                i++;
            }
        }
        return res;
    }
}