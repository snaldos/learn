import { useEffect, useState } from "react";
import "./styles.css";

export default function LoadMoreData() {
  const [loading, setLoading] = useState(true);
  const [products, setProducts] = useState([]);
  const [count, setCount] = useState(0);
  const [disableButton, setDisableButton] = useState(false);

  async function fetchProducts() {
    try {
      const response = await fetch(`https://dummyjson.com/products?limit=20&skip=${count * 20}`);

      const result = await response.json();

      if (result && result.products && result.products.length) {
        setProducts((prevData) => {
          let productsList = [...prevData, ...result.products];
          productsList = productsList.filter((item, index) => {
            return item.id === index + 1;
          });
          return productsList;
        });
        setLoading(false);
      }
    } catch (e) {
      console.log(e);
    }
  }

  useEffect(() => {
    fetchProducts();
  }, [count]);

  useEffect(() => {
    if (products && products.length === 100) setDisableButton(true);
  }, [products]);

  if (loading) {
    return <div>Loading data ! Please wait.</div>;
  }

  return (
    <div className="load-more-container">
      <div className="product-container">
        {products && products.length
          ? products.map((item, index) => (
              <div className="product" key={index}>
                <img src={item.thumbnail} alt={item.title} />
                <p>{item.title}</p>
              </div>
            ))
          : null}
      </div>
      <div className="button-container">
        <button disabled={disableButton} onClick={() => setCount(count + 1)}>
          Load More Products
        </button>
        {disableButton ? <p>You have reached to 100 products.</p> : null}
      </div>
    </div>
  );
}
