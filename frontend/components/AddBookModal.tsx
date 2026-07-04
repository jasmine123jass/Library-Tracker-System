"use client";

import { useEffect, useState } from "react";
import { Book } from "@/types/book";

interface Props {
  onSave: (book: Book) => void;
  editBook?: Book | null;
}

export default function AddBookModal({ onSave, editBook }: Props) {

  const [open, setOpen] = useState(false);

  const [title, setTitle] = useState("");
  const [author, setAuthor] = useState("");
  const [category, setCategory] = useState("");
  const [year, setYear] = useState("");

  useEffect(() => {

    if (editBook) {

      setOpen(true);

      setTitle(editBook.title);
      setAuthor(editBook.author);
      setCategory(editBook.category);
      setYear(editBook.publishedYear.toString());

    }

  }, [editBook]);

  const clearForm = () => {

    setTitle("");
    setAuthor("");
    setCategory("");
    setYear("");

  };

  const saveBook = () => {

    if (!title || !author || !category || !year) {

      alert("Please fill all fields");
      return;

    }

    onSave({

      id: editBook ? editBook.id : Date.now(),

      title,

      author,

      category,

      publishedYear: Number(year),

      status: editBook ? editBook.status : "Available",

    });

    clearForm();

    setOpen(false);

  };

  const closeModal = () => {

    clearForm();

    setOpen(false);

  };

  return (

    <>

      {!editBook && (

        <button
          onClick={() => setOpen(true)}
          className="bg-blue-600 hover:bg-blue-700 px-5 py-2 rounded-lg font-semibold"
        >
          + Add Book
        </button>

      )}

      {open && (

        <div className="fixed inset-0 bg-black/60 flex items-center justify-center">

          <div className="bg-slate-900 p-8 rounded-xl w-[420px]">

            <h2 className="text-2xl font-bold mb-6">

              {editBook ? "Edit Book" : "Add Book"}

            </h2>

            <div className="space-y-4">

              <input
                className="w-full p-3 rounded bg-slate-800"
                placeholder="Book Title"
                value={title}
                onChange={(e) => setTitle(e.target.value)}
              />

              <input
                className="w-full p-3 rounded bg-slate-800"
                placeholder="Author"
                value={author}
                onChange={(e) => setAuthor(e.target.value)}
              />

              <input
                className="w-full p-3 rounded bg-slate-800"
                placeholder="Category"
                value={category}
                onChange={(e) => setCategory(e.target.value)}
              />

              <input
                className="w-full p-3 rounded bg-slate-800"
                placeholder="Published Year"
                value={year}
                onChange={(e) => setYear(e.target.value)}
              />

            </div>

            <div className="flex justify-end gap-3 mt-6">

              <button
                onClick={closeModal}
                className="bg-slate-700 px-4 py-2 rounded"
              >
                Cancel
              </button>

              <button
                onClick={saveBook}
                className="bg-blue-600 hover:bg-blue-700 px-4 py-2 rounded"
              >
                Save
              </button>

            </div>

          </div>

        </div>

      )}

    </>

  );

}