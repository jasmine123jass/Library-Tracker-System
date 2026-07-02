export interface Book {
  id: number;
  title: string;
  author: string;
  category: string;
  status: "Available" | "Borrowed";
  publishedYear: number;
}