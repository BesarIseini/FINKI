package FrontPageTest;

import java.util.*;
import java.util.stream.Collectors;

public class FrontPageTest {
    public static void main(String[] args) {
        // Reading
        Scanner scanner = new Scanner(System.in);
        String line = scanner.nextLine();
        String[] parts = line.split(" ");
        Category[] categories = new Category[parts.length];
        for (int i = 0; i < categories.length; ++i) {
            categories[i] = new Category(parts[i]);
        }
        int n = scanner.nextInt();
        scanner.nextLine();
        FrontPage frontPage = new FrontPage(categories);
        Calendar cal = Calendar.getInstance();
        for (int i = 0; i < n; ++i) {
            String title = scanner.nextLine();
            cal = Calendar.getInstance();
            int min = scanner.nextInt();
            cal.add(Calendar.MINUTE, -min);
            Date date = cal.getTime();
            scanner.nextLine();
            String text = scanner.nextLine();
            int categoryIndex = scanner.nextInt();
            scanner.nextLine();
            TextNewsItem tni = new TextNewsItem(title, date, categories[categoryIndex], text);
            frontPage.addNewsItem(tni);
        }

        n = scanner.nextInt();
        scanner.nextLine();
        for (int i = 0; i < n; ++i) {
            String title = scanner.nextLine();
            int min = scanner.nextInt();
            cal = Calendar.getInstance();
            cal.add(Calendar.MINUTE, -min);
            scanner.nextLine();
            Date date = cal.getTime();
            String url = scanner.nextLine();
            int views = scanner.nextInt();
            scanner.nextLine();
            int categoryIndex = scanner.nextInt();
            scanner.nextLine();
            MediaNewsItem mni = new MediaNewsItem(title, date, categories[categoryIndex], url, views);
            frontPage.addNewsItem(mni);
        }
        // Execution
        String category = scanner.nextLine();
        System.out.println(frontPage);
        for(Category c : categories) {
            System.out.println(frontPage.listByCategory(c).size());
        }
        try {
            System.out.println(frontPage.listByCategoryName(category).size());
        } catch(CategoryNotFoundException e) {
            System.out.println(e.getMessage());
        }
    }
}


class Category {
    private String name;

    public Category(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }
}

abstract class NewsItem {
    private String title;
    private Date publicationDate;
    private Category category;

    public NewsItem(String title, Date publicationDate, Category category) {
        this.title = title;
        this.publicationDate = publicationDate;
        this.category = category;
    }

    public Category getCategory() {
        return category;
    }

    public abstract String getTeaser();

    public long minutesAgo() {
        return (new Date().getTime() - publicationDate.getTime()) / (60 * 1000);
    }

    public String getTitle() {
        return title;
    }
}

class TextNewsItem extends NewsItem {
    private String text;

    public TextNewsItem(String title, Date publicationDate, Category category, String text) {
        super(title, publicationDate, category);
        this.text = text;
    }


    @Override
    public String getTeaser() {


        String shortText = text.length() > 80 ? text.substring(0, 80) : text;

        return getTitle() + "\n" + minutesAgo() + "\n" + shortText + "\n";
    }

}

class MediaNewsItem extends NewsItem {
    private String url;
    private int views;

    public MediaNewsItem(String title, Date publicationDate, Category category, String url, int views) {
        super(title, publicationDate, category);
        this.url = url;
        this.views = views;
    }

    @Override
    public String getTeaser() {
        return  getTitle() + "\n" + minutesAgo() + "\n" + url + "\n" + views + "\n";
    }
}

class FrontPage {
    private ArrayList<NewsItem> newsItems = new ArrayList<>();
    private Category[] categories;

    public FrontPage(Category[] categories) {
        this.categories = categories;
    }

    public void addNewsItem(NewsItem newsItem) {
        newsItems.add(newsItem);
    }

    public List<NewsItem> listByCategory(Category category) {
        List<NewsItem> filtered = newsItems.stream().filter(n -> n.getCategory() == category).collect(Collectors.toCollection(ArrayList::new));

        return filtered;
    }

    List<NewsItem> listByCategoryName(String category) throws CategoryNotFoundException {

        boolean exists = Arrays.stream(categories).anyMatch(c -> c.getName().equals(category));
        if (!exists) throw new CategoryNotFoundException(category);


        List<NewsItem> filtered = newsItems.stream().filter(n -> n.getCategory().getName().equals(category)).collect(Collectors.toCollection(ArrayList::new));


        return filtered;
    }

    public String toString() {
        return newsItems.stream()
                .map(NewsItem::getTeaser)
                .collect(Collectors.joining());
    }
}

class CategoryNotFoundException extends Exception {
    CategoryNotFoundException(String category) {
        super(String.format("Category %s was not found", category));
    }
}