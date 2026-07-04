"use client";

import { Book } from "@/types/book";

interface Props {
  books: Book[];
  onDelete: (id: number) => void;
  onEdit: (book: Book) => void;
}

export default function BooksTable({
  books,
  onDelete,
  onEdit,
}: Props) {
  return (
    <div className="mt-8 overflow-hidden rounded-xl border border-slate-800">
      <table className="w-full">

        <thead className="bg-slate-900">
          <tr>
            <th className="p-4 text-left">Title</th>
            <th className="p-4 text-left">Author</th>
            <th className="p-4 text-left">Category</th>
            <th className="p-4 text-left">Year</th>
            <th className="p-4 text-left">Status</th>
            <th className="p-4 text-center">Actions</th>
          </tr>
        </thead>

        <tbody>
          {books.map((book) => (
            <tr
              key={book.id}
              className="border-t border-slate-800 hover:bg-slate-900"
            >
              <td className="p-4">{book.title}</td>

              <td className="p-4">{book.author}</td>

              <td className="p-4">{book.category}</td>

              <td className="p-4">{book.publishedYear}</td>

              <td className="p-4">
                <span
                  className={`px-3 py-1 rounded-full text-sm ${
                    book.status === "Available"
                      ? "bg-green-600"
                      : "bg-red-600"
                  }`}
                >
                  {book.status}
                </span>
              </td>

              <td className="p-4 text-center">
                <button
                  onClick={() => onEdit(book)}
                  className="bg-blue-600 hover:bg-blue-700 px-3 py-1 rounded mr-2"
                >
                  Edit
                </button>

                <button
                  onClick={() => {
                    if (confirm("Delete this book?")) {
                      onDelete(book.id);
                    }
                  }}
                  className="bg-red-600 hover:bg-red-700 px-3 py-1 rounded"
                >
                  Delete
                </button>
              </td>
            </tr>
          ))}
        </tbody>

      </table>
    </div>
  );
}